import random

# Establishes a player class with the variables all set to their default values
class Player:
    def __init__(self, name) -> None:
        self.name = name
        self.level = 1
        self.experience = 0
        self.coins = 0
        self.inventory = {
            'fishing_rod': True,
            'bait': 10
        }
        self.bucket = []
    
    # Method for fishing
    def fish(self):
        if self.inventory['bait'] > 0:
            fish = random.choice(['Goldfish', 'Cod', 'Bass', 'Salmon'])
            size = random.randint(1, 10)
            print(f"You caught a {fish} weighing {size} pounds!")
            self.experience += 1
            self.inventory['bait'] -= 1
        else:
            print("You have no bait :(")

    # Method for displaying stats
    def display_stats(self):
        print(f"Name: {self.name}")
        print(f"Level: {self.level}")
        print(f"Experience {self.experience}")
        print(f"Bait: {self.inventory['bait']}")


# Main loop of the game
def Main():
    print("""\

  _   _ _ _   _            _         ___ _    _    _             ___ _           _      _            
 | | | | | |_(_)_ __  __ _| |_ ___  | __(_)__| |_ (_)_ _  __ _  / __(_)_ __ _  _| |__ _| |_ ___ _ _  
 | |_| | |  _| | '  \/ _` |  _/ -_) | _|| (_-< ' \| | ' \/ _` | \__ \ | '  \ || | / _` |  _/ _ \ '_| 
  \___/|_|\__|_|_|_|_\__,_|\__\___| |_| |_/__/_||_|_|_||_\__, | |___/_|_|_|_\_,_|_\__,_|\__\___/_|   
                      ___      _                ___    _ |___/ _                                     
                     |   \ ___| |_  ___ _____  | __|__| (_) |_(_)___ _ _                             
                     | |) / -_) | || \ \ / -_) | _|/ _` | |  _| / _ \ ' \                            
                     |___/\___|_|\_,_/_\_\___| |___\__,_|_|\__|_\___/_||_|                           
                                                                                                     

    """)
    print("\n")
    name = input("Enter your name: ")
    player = Player(name)

    while True:
        print("\n1. Fish")
        print("2. Display Stats")
        print("3. Quit")

        choice = input("Enter your choice: ")

        if choice == '1':
            player.fish()
        elif choice == '2':
            player.display_stats()
        elif choice == '3':
            print("Bye o/")
            break
        else:
            print ("I no no wanna :( \n Try again")

if __name__ == "__main__":
    Main()