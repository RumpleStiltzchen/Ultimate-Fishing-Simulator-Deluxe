#pragma once
#include <raylib.h>
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <sstream>
#include <fstream>


struct Fish
{

    Fish()
    {

    }
    Fish(int baseSalePrice, float minWeight, float maxWeight, int tier, int chance, std::string name, std::string path, std::string internalName)
    {
        this->baseSalePrice = baseSalePrice;
        this->minWeight = minWeight;
        this->maxWeight = maxWeight;
        this->tier = tier;
        this->chance = chance;
        this->name = name;
        this->path = path;
        this->internalName = internalName;
        std::stringstream ss;
        ss << "resources/" << internalName << ".png";
        this->sprite = LoadTexture(ss.str().c_str());
    }
    public:
        void printInfo(bool verbose = false)
        {   
            std::cout << 
            "\nName:\t" << name << 
            "\nID:\t" << internalName;
            
            if(verbose)
            {
                std::cout << 
                "\nPrice:\t" << baseSalePrice <<
                "\nTier:\t" << tier <<
                "\nChance:\t" << chance << 
                "\nMaxWeight:\t" << maxWeight <<
                "\nMinWeight:\t" << minWeight <<
                "\nPath:\t" << path;
            }
        }
    public:
        int baseSalePrice;
        float minWeight;
        float maxWeight;
        int tier;
        int chance;
        std::string name;
        std::string path;
        std::string internalName;
        Texture2D sprite;



};

std::vector<Fish*> GetFish(std::string path)
{
    namespace fs = std::filesystem;
    std::vector<Fish*> fishes;
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << entry.path().filename().string() << "\n";
        if (entry.is_directory()) {
            std::string folderName = entry.path().filename().string();

            std::stringstream ss;
            ss << entry.path().string() << "/" << folderName << ".fsh";

            std::ifstream file(ss.str());

            if (file.is_open()) {
                std::string salePrice, minWeight, maxWeight, tier, chance, name;
                std::getline(file, salePrice);
                std::getline(file, minWeight);
                std::getline(file, maxWeight);
                std::getline(file, tier);
                std::getline(file, chance);
                std::getline(file, name);
                fishes.push_back(
                    new Fish(
                        std::stoi(salePrice), 
                        std::stof(minWeight),
                        std::stof(maxWeight), 
                        std::stoi(tier), 
                        std::stoi(chance), 
                        name, 
                        entry.path().string(),
                        entry.path().filename().string()
                        )
                    );
                file.close();
            } else {
                std::cerr << "Unable to open file " << std::endl;
            }
        }
    }
    return fishes;
}
