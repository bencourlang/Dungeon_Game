#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <iomanip>
#include <vector>
//#include <stdlib.h>
using namespace std;
using namespace std::chrono;

//************************************************************************* Adventurer Class *************************************************************************
#ifndef ADVENTURER_H
#define ADVENTURER_H
class Adventurer{
    private:
        string type;
        int level;
        int health;
        int attack;
        int defense;
        int evasion;
        int magic;
        bool isDead;
    public:
        Adventurer();
        Adventurer(string, int, int, int, int, int, int, bool);
        string getType();
        int getLevel();
        int getHealth();
        int getAttack();
        int getDefense();
        int getEvasion();
        int getMagic();
        bool getIsDead();
        string print();
        void damage(int);
};
#endif

Adventurer::Adventurer(){
    type = "";
    level = -1;
    health = -1;
    attack = -1;
    defense = -1;
    evasion = -1;
    magic = -1;
    isDead = false;
}

Adventurer::Adventurer(string advType, int advLevel, int advHealth, int advAttack, int advDefense, int advEvasion, int advMagic, bool advIsDead){
    type = advType;
    level = advLevel;
    health = advHealth;
    attack = advAttack;
    defense = advDefense;
    evasion = advEvasion;
    magic = advMagic;
    isDead = advIsDead;
}

string Adventurer::getType(){
    return type;
}

int Adventurer::getLevel(){
    return level;
}

int Adventurer::getHealth(){
    return health;
}

int Adventurer::getAttack(){
    return attack;
}

int Adventurer::getDefense(){
    return defense;
}

int Adventurer::getEvasion(){
    return evasion;
}

int Adventurer::getMagic(){
    return magic;
}

bool Adventurer::getIsDead(){
    return isDead;
}

string Adventurer::print(){
    return ("level " + to_string(level) + " " + type + ":\n   " + "Health: " + to_string(health) + "\n   " + "Attack: " + 
    to_string(attack) + "\n   " + "Defense: " + to_string(defense) + "\n   " + "Evasion: " + to_string(evasion) + "\n   " + "Magic: " + to_string(magic));
}

void Adventurer::damage(int dmg){
    health -= dmg;
    cout << "The level " << level << " " << type << " took \033[1;31m" << dmg << "\033[0m damage\n"; 
    if(health < 1){
        isDead = true;
        cout << "\033[1;31mThe level " + to_string(level) + " " + type + " is dead\033[0m\n";
    }
}

int totalAdvs = 9;

//************************************************************************* Adventurer Maker *************************************************************************
Adventurer characterCreator(string type, int level){
    int role = -1;
    int health = -1;
    int attack = -1;
    int defense = -1;
    int evasion = -1;
    int magic = -1;

    if(type == "Warrior"){
        role = 1;
    }
    else if(type == "Rogue"){
        role = 2;
    }
    else if(type == "Wizard"){
        role = 3;
    }
    else{
        throw invalid_argument("Class does not work");
    }

    switch (role){
        case 1: //Warrior
            switch (level){
                case 1:
                    health = rand()%10 + 1;
                    attack = rand()%8 + 1;
                    defense = rand()%3 + 1;
                    evasion = rand()%2;
                    magic = 0;
                    break;

                case 2:
                    health = rand()%10 + rand()%10 + 2;
                    attack = rand()%8 + rand()%8 + 2;
                    defense = rand()%3 + rand()%3 + 2;
                    evasion = rand()%2 + rand()%2;
                    magic = 0;
                    break;

                case 3:
                    health = rand()%10 + rand()%10 + rand()%10 + 3;
                    attack = rand()%8 + rand()%8 + rand()%8 + 3;
                    defense = rand()%3 + rand()%3 + rand()%3 + 3;
                    evasion = rand()%2 + rand()%2 + rand()%2;
                    magic = 0;
                    break;
                
                default:
                    throw invalid_argument("Level does not work");
                    break;
                }
                break;

        case 2: //Rogue
            switch (level){
                case 1:
                    health = rand()%8 + 1;
                    attack = rand()%10 + 1;
                    defense = rand()%2;
                    evasion = rand()%10 + 1;
                    magic = rand()%4;
                    break;

                case 2:
                    health = rand()%8 + rand()%8 + 2;
                    attack = rand()%10 + rand()%10 + 2;
                    defense = rand()%2 + rand()%2;
                    evasion = rand()%10 + rand()%10 + 2;
                    magic = rand()%4 + rand()%4;
                    break;

                case 3:
                    health = rand()%8 + rand()%8 + rand()%8 + 3;
                    attack = rand()%10 + rand()%10 + rand()%10 + 3;
                    defense = rand()%2 + rand()%2 + rand()%2;
                    evasion = rand()%10 + rand()%10 + rand()%10 + 3;
                    magic = rand()%4 + rand()%4 + rand()%4;
                    break;
                
                default:
                    throw invalid_argument("Level does not work");
                    break;
                }
            break;

        case 3: //Wizard
            switch (level){
                case 1:
                    health = rand()%6 + 1;
                    attack = rand()%4 + 1;
                    defense = 0;
                    evasion = rand()%2;
                    magic = rand()%10 + 1;
                    break;

                case 2:
                    health = rand()%6 + rand()%6 + 2;
                    attack = rand()%4 + rand()%4 + 2;
                    defense = 0;
                    evasion = rand()%2 + rand()%2;
                    magic = rand()%10 + rand()%10 + 2;
                    break;

                case 3:
                    health = rand()%6 + rand()%6 + rand()%6 + 3;
                    attack = rand()%4 + rand()%4 + rand()%4 + 3;
                    defense = 0;
                    evasion = rand()%2 + rand()%2 + rand()%2;
                    magic = rand()%10 + rand()%10 + rand()%10 + 3;
                    break;
                
                default:
                    throw invalid_argument("Level does not work");
                    break;
            }
            break;
        
        default:
            throw invalid_argument("Class does not work");
            break;
    }
    return Adventurer(type, level, health, attack, defense, evasion, magic, false);
}


//************************************************************************* Party Class *************************************************************************
#ifndef PARTY_H
#define PARTY_H

class Party{
    private:
        Adventurer *adv;
    public:
        Party();
        void showAdv();
        Adventurer getAdv();
        Adventurer getAdvLvlOne();
        Adventurer getAdvLvlTwo();
        Adventurer getAdvLvlThree();
};
#endif

Party::Party(){
    string types[] = {"Warrior", "Rogue", "Wizard"};
    int levels[] = {1, 2, 3};
    adv = new Adventurer[totalAdvs];
    for(int i = 0; i < totalAdvs; i++){
        adv[i] = characterCreator(types[i%3], levels[i/3]);
    }
}

void Party::showAdv(){
    for(int i = 0; i < totalAdvs; i++){
        cout << adv[i].print() << "\n" << endl;
    }
}

Adventurer Party::getAdv(){
    string types[] = {"Warrior", "Rogue", "Wizard"};
    return characterCreator(types[rand()%3], (rand()%3 + 1));
    return adv[rand()%totalAdvs];
}

Adventurer Party::getAdvLvlOne(){
    string types[] = {"Warrior", "Rogue", "Wizard"};
    return characterCreator(types[rand()%3], 1);
}

Adventurer Party::getAdvLvlTwo(){
    string types[] = {"Warrior", "Rogue", "Wizard"};
    return characterCreator(types[rand()%3], 2);
}

Adventurer Party::getAdvLvlThree(){
    string types[] = {"Warrior", "Rogue", "Wizard"};
    return characterCreator(types[rand()%3], 3);
}


//************************************************************************* Rooms Class *************************************************************************
#ifndef ROOMS_H
#define ROOMS_H
class Rooms{
    private:
        string type;
        int stars;
    public:
        Rooms();
        Rooms(string, int);
        string getType();
        int getStars();
        string print();
};
#endif

Rooms::Rooms(){
    type = "";
    stars = -1;
}

Rooms::Rooms(string roomType, int roomStars){
    type = roomType;
    stars = roomStars;
}

string Rooms::getType(){
    return type;
}

int Rooms::getStars(){
    return stars;
}

string Rooms::print(){
    return(type + " room that is a " + to_string(stars) + " star quality");
}

int totalRooms = 30;

//************************************************************************* AllRooms Class *************************************************************************
#ifndef ALLROOMS_H
#define ALLROOMS_H
class AllRooms{
    private:
        Rooms *rooms;
    public:
        AllRooms();
        void showAllRooms();
        Rooms getRoom();
        Rooms getRoomLvlOne();
        Rooms getRoomLvlTwo();
        Rooms getRoomLvlThree();

        Rooms getCombatRoom();
};
#endif

AllRooms::AllRooms(){
    string types[] = {"Falling Boulder Trap", "Magic Circle Trap", "Pit Fall Trap", "Slime Combat", "Goblin Combat", "Skeleton Combat", 
    "Stone Wall Skill Check", "Magic Wall Skill Check", "Parkour Skill Check", "Empty"};
    int stars[] = {1, 2, 3};
    rooms = new Rooms[totalRooms];
    for(int i = 0; i < totalRooms; i++){
        rooms[i] = Rooms(types[i%10], stars[i/10]);
    }
}

void AllRooms::showAllRooms(){
    for(int i = 0; i < totalRooms; i++){
        cout << rooms[i].print() << "\n" << endl;
    }
}

Rooms AllRooms::getRoom(){
    return rooms[rand()%totalRooms];
}

Rooms AllRooms::getRoomLvlOne(){
    return rooms[rand()%10];
}

Rooms AllRooms::getRoomLvlTwo(){
    return rooms[rand()%10 + 10];
}

Rooms AllRooms::getRoomLvlThree(){
    return rooms[rand()%10 + 20];
}

Rooms AllRooms::getCombatRoom(){
    return rooms[rand()%3 + 3];
}

Adventurer minionCreator(string type, int level){
    int role = -1;
    int health = -1;
    int attack = -1;
    int defense = -1;
    int evasion = -1;
    int magic = -1;

    if(type == "Slime"){
        role = 1;
    }
    else if(type == "Goblin"){
        role = 2;
    }
    else if(type == "Skeleton"){
        role = 3;
    }
    else{
        throw invalid_argument("Class does not work");
    }

    switch (role){
        case 1: //Slime
            switch (level){
                case 1:
                    health = rand()%8 + 1;
                    attack = rand()%6 + 1;
                    defense = rand()%3 + 1;
                    evasion = rand()%5 + 1;
                    magic = 0;
                    break;

                case 2:
                    health = rand()%8 + rand()%8 + 2;
                    attack = rand()%6 + rand()%6 + 2;
                    defense = rand()%3 + rand()%3 + 2;
                    evasion = rand()%5 + rand()%5 + 2;
                    magic = 0;
                    break;

                case 3:
                    health = rand()%8 + rand()%8 + rand()%8 + 3;
                    attack = rand()%6 + rand()%6 + rand()%6 + 3;
                    defense = rand()%3 + rand()%3 + rand()%3 + 3;
                    evasion = rand()%5 + rand()%5 + rand()%5 + 3;
                    magic = 0;
                    break;
                
                default:
                    throw invalid_argument("Level does not work");
                    break;
            }
            break;

        case 2: //Goblin
            switch (level){
                case 1:
                    health = rand()%6 + 1;
                    attack = rand()%10 + 1;
                    defense = rand()%2;
                    evasion = rand()%10 + 1;
                    magic = 0;
                    break;

                case 2:
                    health = rand()%6 + rand()%6 + 2;
                    attack = rand()%10 + rand()%10 + 2;
                    defense = rand()%2 + rand()%2;
                    evasion = rand()%10 + rand()%10 + 2;
                    magic = 0;
                    break;

                case 3:
                    health = rand()%6 + rand()%6 + rand()%6 + 3;
                    attack = rand()%10 + rand()%10 + rand()%10 + 3;
                    defense = rand()%2 + rand()%2 + rand()%2;
                    evasion = rand()%10 + rand()%10 + rand()%10 + 3;
                    magic = 0;
                    break;
                
                default:
                    throw invalid_argument("Level does not work");
                    break;
            }
            break;

        case 3: //Skeleton
            switch (level){
                case 1:
                    health = rand()%10 + 1;
                    attack = rand()%4 + 1;
                    defense = rand()%5 + 1;
                    evasion = 0;
                    magic = 0;
                    break;

                case 2:
                    health = rand()%10 + rand()%10 + 2;
                    attack = rand()%4 + rand()%4 + 2;
                    defense = rand()%5 + rand()%5 + 2;
                    evasion = 0;
                    magic = 0;
                    break;

                case 3:
                    health = rand()%10 + rand()%10 + rand()%10 + 3;
                    attack = rand()%4 + rand()%4 + rand()%4 + 3;
                    defense = rand()%5 + rand()%5 + rand()%5 + 3;
                    evasion = 0;
                    magic = 0;
                    break;
                
                default:
                    throw invalid_argument("Level does not work");
                    break;
            }
            break;
        
        default:
            throw invalid_argument("Class does not work");
            break;
    }
    return Adventurer(type, level, health, attack, defense, evasion, magic, false);
}


int totalMinions = 9;
//************************************************************************* Gang Class *************************************************************************
#ifndef GANG_H
#define GANG_H

class Gang{
    private:
        Adventurer *min;
    public:
        Gang();
        void showMinion();
        Adventurer getMinion();
        Adventurer getMinionLvlOne();
        Adventurer getMinionLvlTwo();
        Adventurer getMinionLvlThree();

        Adventurer getSlime();
        Adventurer getSlimeLvlOne();
        Adventurer getSlimeLvlTwo();
        Adventurer getSlimeLvlThree();

        Adventurer getGoblin();
        Adventurer getGoblinLvlOne();
        Adventurer getGoblinLvlTwo();
        Adventurer getGoblinLvlThree();

        Adventurer getSkeleton();
        Adventurer getSkeletonLvlOne();
        Adventurer getSkeletonLvlTwo();
        Adventurer getSkeletonLvlThree();
};
#endif

Gang::Gang(){
    string types[] = {"Slime", "Goblin", "Skeleton"};
    int levels[] = {1, 2, 3};
    min = new Adventurer[totalMinions];
    for(int i = 0; i < totalMinions; i++){
        min[i] = minionCreator(types[i%3], levels[i/3]);
    }
}

void Gang::showMinion(){
    for(int i = 0; i < totalMinions; i++){
        cout << min[i].print() << "\n" << endl;
    }
}

Adventurer Gang::getMinion(){
    return min[rand()%totalMinions];
}

Adventurer Gang::getMinionLvlOne(){
    return min[rand()%3];
}

Adventurer Gang::getMinionLvlTwo(){
    return min[rand()%3 + 3];
}

Adventurer Gang::getMinionLvlThree(){
    return min[rand()%3 + 6];
}

Adventurer Gang::getSlime(){
    int lvl = rand()%3 + 1;
    return (minionCreator("Slime", lvl));
}

Adventurer Gang::getSlimeLvlOne(){
    return (minionCreator("Slime", 1));
}

Adventurer Gang::getSlimeLvlTwo(){
    return (minionCreator("Slime", 2));
}

Adventurer Gang::getSlimeLvlThree(){
    return (minionCreator("Slime", 3));
}

Adventurer Gang::getGoblin(){
    int lvl = rand()%3 + 1;
    return (minionCreator("Goblin", lvl));
}

Adventurer Gang::getGoblinLvlOne(){
    return (minionCreator("Goblin", 1));
}

Adventurer Gang::getGoblinLvlTwo(){
    return (minionCreator("Goblin", 2));
}

Adventurer Gang::getGoblinLvlThree(){
    return (minionCreator("Goblin", 3));
}

Adventurer Gang::getSkeleton(){
    int lvl = rand()%3 + 1;
    return (minionCreator("Skeleton", lvl));
}

Adventurer Gang::getSkeletonLvlOne(){
    return (minionCreator("Skeleton", 1));
}

Adventurer Gang::getSkeletonLvlTwo(){
    return (minionCreator("Skeleton", 2));
}

Adventurer Gang::getSkeletonLvlThree(){
    return (minionCreator("Skeleton", 3));
}




//****************************************************************** Functions ***********************************************************************

void clearScreen(){
    cout << string(20, '\n');
}

void roomWork(Rooms dungeon[], Rooms tutOp1, Rooms tutOp2, Rooms tutOp3){
    bool rWork = false;
    bool spotWork = false;
    string roomOp;
    string spotOp;

    while(rWork == false){
        cout << "Choose a new room\n";
        cout << "1. " << tutOp1.print() << endl;
        cout << "2. " << tutOp2.print() << endl;
        cout << "3. " << tutOp3.print() << "\n" << endl;
        cin >> roomOp;
        if(roomOp == "1"){
            while(spotWork == false){
                cout << "Now choose where in your dungeon you want to put your new room. Don't worry you can rearrange your dungeon if you get a dungeon renovation\n" << endl;
                cout << "Your dungeon looks like:" << endl;
                for(int i = 0; i < 5; i++){
                    if(dungeon[i].getType() == ""){
                        cout << "\033[1;32m" << i + 1 << ". \033[0m_____";
                    }
                    else{
                        cout << "\033[1;32m" << i + 1 << ". \033[0m\033[4m" << dungeon[i].getType() << "\033[0m";
                    }
                    cout << "      ";
                }
                cout << endl << endl;

                cin >> spotOp;
                if(spotOp == "1" && dungeon[0].getType() == ""){
                    dungeon[0] = tutOp1;
                    spotWork = true;
                }
                else if(spotOp == "2" && dungeon[1].getType() == ""){
                    dungeon[1] = tutOp1;
                    spotWork = true;
                }
                else if(spotOp == "3" && dungeon[2].getType() == ""){
                    dungeon[2] = tutOp1;
                    spotWork = true;
                }
                else if(spotOp == "4" && dungeon[3].getType() == ""){
                    dungeon[3] = tutOp1;
                    spotWork = true;
                }
                else if(spotOp == "5" && dungeon[4].getType() == ""){
                    dungeon[4] = tutOp1;
                    spotWork = true;
                }
                else{
                    cout << "Choose an open spot:" << endl;
                }
            }
            rWork = true;
        }
        else if(roomOp == "2"){
            while(spotWork == false){
                cout << "Now choose where in your dungeon you want to put your new room. Don't worry you can rearrange your dungeon if you get a dungeon renovation\n" << endl;
                cout << "Your dungeon looks like:" << endl;
                for(int i = 0; i < 5; i++){
                    if(dungeon[i].getType() == ""){
                        cout << "\033[1;32m" << i + 1 << ". \033[0m_____";
                    }
                    else{
                        cout << "\033[1;32m" << i + 1 << ". \033[0m\033[4m" << dungeon[i].getType() << "\033[0m";
                    }
                    cout << "      ";
                }
                cout << endl << endl;

                cin >> spotOp;
                if(spotOp == "1" && dungeon[0].getType() == ""){
                    dungeon[0] = tutOp2;
                    spotWork = true;
                }
                else if(spotOp == "2" && dungeon[1].getType() == ""){
                    dungeon[1] = tutOp2;
                    spotWork = true;
                }
                else if(spotOp == "3" && dungeon[2].getType() == ""){
                    dungeon[2] = tutOp2;
                    spotWork = true;
                }
                else if(spotOp == "4" && dungeon[3].getType() == ""){
                    dungeon[3] = tutOp2;
                    spotWork = true;
                }
                else if(spotOp == "5" && dungeon[4].getType() == ""){
                    dungeon[4] = tutOp2;
                    spotWork = true;
                }
                else{
                    cout << "Choose an open spot:" << endl;
                }
            }
            rWork = true;
        }
        else if(roomOp == "3"){
            while(spotWork == false){
                cout << "Now choose where in your dungeon you want to put your new room. Don't worry you can rearrange your dungeon if you get a dungeon renovation\n" << endl;
                cout << "Your dungeon looks like:" << endl;
                for(int i = 0; i < 5; i++){
                    if(dungeon[i].getType() == ""){
                        cout << "\033[1;32m" << i + 1 << ". \033[0m_____";
                    }
                    else{
                        cout << "\033[1;32m" << i + 1 << ". \033[0m\033[4m" << dungeon[i].getType() << "\033[0m";
                    }
                    cout << "      ";
                }
                cout << endl << endl;

                cin >> spotOp;
                if(spotOp == "1" && dungeon[0].getType() == ""){
                    dungeon[0] = tutOp3;
                    spotWork = true;
                }
                else if(spotOp == "2" && dungeon[1].getType() == ""){
                    dungeon[1] = tutOp3;
                    spotWork = true;
                }
                else if(spotOp == "3" && dungeon[2].getType() == ""){
                    dungeon[2] = tutOp3;
                    spotWork = true;
                }
                else if(spotOp == "4" && dungeon[3].getType() == ""){
                    dungeon[3] = tutOp3;
                    spotWork = true;
                }
                else if(spotOp == "5" && dungeon[4].getType() == ""){
                    dungeon[4] = tutOp3;
                    spotWork = true;
                }
                else{
                    cout << "Choose an open spot:" << endl;
                }
            }
            rWork = true;
        }
        else{
            cout << "Choose a room:" << endl;
        }
    }
}

bool existMob(vector<Adventurer> &initiative){
    for(int i = 0; i < initiative.size(); i++){
        if((initiative[i].getType() == "Slime" || initiative[i].getType() == "Goblin" || initiative[i].getType() == "Skeleton") && initiative[i].getIsDead() == false){
            return true;
        }
    }
    return false;
}

int findFirstMob(vector<Adventurer> &initiative){
    for(int i = 0; i < initiative.size(); i++){
        if((initiative[i].getType() == "Slime" || initiative[i].getType() == "Goblin" || initiative[i].getType() == "Skeleton") && initiative[i].getIsDead() == false){
            return i;
        }
    }
    return -1;
}

bool existAdv(vector<Adventurer> &initiative){
    for(int i = 0; i < initiative.size(); i++){
        if((initiative[i].getType() == "Warrior" || initiative[i].getType() == "Rogue" || initiative[i].getType() == "Wizard") && initiative[i].getIsDead() == false){
            return true;
        }
    }
    return false;
}

int findFirstAdv(vector<Adventurer> &initiative){
    for(int i = 0; i < initiative.size(); i++){
        if((initiative[i].getType() == "Warrior" || initiative[i].getType() == "Rogue" || initiative[i].getType() == "Wizard") && initiative[i].getIsDead() == false){
            return i;
        }
    }
    return -1;
}

bool strTrap(vector<Adventurer> &raid, Rooms room){
    int pass = 5;
    int dmg = 5;
    if(room.getStars() == 1){
        for(int i = 0; i < raid.size(); i++){
            if(raid[i].getIsDead() == false){
                if(raid[i].getAttack() > pass*3){
                    cout << "The " << raid[i].getType() << " easily beat the trap, taking no damage" << endl;
                }
                else if(raid[i].getAttack() > pass){
                    cout << "The " << raid[i].getType() << " beat the trap, taking half damage" << endl;
                    raid[i].damage((dmg/2));
                }
                else{
                    cout << "The " << raid[i].getType() << " got caught in the trap, taking full damage" << endl;
                    raid[i].damage(dmg);
                }
            }
        }
    }
    else if(room.getStars() == 2){
        for(int i = 0; i < raid.size(); i++){
            if(raid[i].getIsDead() == false){
                if(raid[i].getAttack() > pass*4){
                    cout << "The " << raid[i].getType() << " easily beat the trap, taking no damage" << endl;
                }
                else if(raid[i].getAttack() > (pass*2)){
                    cout << "The " << raid[i].getType() << " beat the trap, taking half damage" << endl;
                    raid[i].damage(dmg);
                }
                else{
                    cout << "The " << raid[i].getType() << " got caught in the trap, taking full damage" << endl;
                    raid[i].damage((dmg*2));
                }
            }
        }
    }
    else if(room.getStars() == 3){
        for(int i = 0; i < raid.size(); i++){
            if(raid[i].getIsDead() == false){
                if(raid[i].getAttack() > pass*5){
                    cout << "The " << raid[i].getType() << " easily beat the trap, taking no damage" << endl;
                }
                else if(raid[i].getAttack() > (pass*3)){
                    cout << "The " << raid[i].getType() << " beat the trap, taking half damage" << endl;
                    raid[i].damage((dmg*1.5));
                }
                else{
                    cout << "The " << raid[i].getType() << " got caught in the trap, taking full damage" << endl;
                    raid[i].damage((dmg*3));
                }
            }
        }
    }
    
    return !existAdv(raid);
}

bool magicTrap(vector<Adventurer> &raid, Rooms room){
    int pass = 4;
    int dmg = 5;
    if(room.getStars() == 1){
        for(int i = 0; i < raid.size(); i++){
            if(raid[i].getIsDead() == false){
                if(raid[i].getMagic() > pass*3){
                    cout << "The " << raid[i].getType() << " easily beat the trap, taking no damage" << endl;
                }
                else if(raid[i].getMagic() > pass){
                    cout << "The " << raid[i].getType() << " beat the trap, taking half damage" << endl;
                    raid[i].damage((dmg/2));
                }
                else{
                    cout << "The " << raid[i].getType() << " got caught in the trap, taking full damage" << endl;
                    raid[i].damage(dmg);
                }
            }

        }
    }
    else if(room.getStars() == 2){
        for(int i = 0; i < raid.size(); i++){
            if(raid[i].getIsDead() == false){
                if(raid[i].getMagic() > pass*4){
                    cout << "The " << raid[i].getType() << " easily beat the trap, taking no damage" << endl;
                }
                else if(raid[i].getMagic() > (pass*2)){
                    cout << "The " << raid[i].getType() << " beat the trap, taking half damage" << endl;
                    raid[i].damage(dmg);
                }
                else{
                    cout << "The " << raid[i].getType() << " got caught in the trap, taking full damage" << endl;
                    raid[i].damage((dmg*2));
                }                
            }
        }
    }
    else if(room.getStars() == 3){
        for(int i = 0; i < raid.size(); i++){
            if(raid[i].getIsDead() == false){
                if(raid[i].getMagic() > pass*5){
                    cout << "The " << raid[i].getType() << " easily beat the trap, taking no damage" << endl;
                }
                else if(raid[i].getMagic() > (pass*3)){
                    cout << "The " << raid[i].getType() << " beat the trap, taking half damage" << endl;
                    raid[i].damage((dmg*1.5));
                }
                else{
                    cout << "The " << raid[i].getType() << " got caught in the trap, taking full damage" << endl;
                    raid[i].damage((dmg*3));
                }
            }
        }
    }

    return !existAdv(raid);
}

bool dexTrap(vector<Adventurer> &raid, Rooms room){
    int pass = 4;
    int dmg = 5;
    if(room.getStars() == 1){
        for(int i = 0; i < raid.size(); i++){
            if(raid[i].getIsDead() == false){
                if(raid[i].getEvasion() > pass*3){
                    cout << "The " << raid[i].getType() << " easily beat the trap, taking no damage" << endl;
                }
                else if(raid[i].getEvasion() > pass){
                    cout << "The " << raid[i].getType() << " beat the trap, taking half damage" << endl;
                    raid[i].damage((dmg/2));
                }
                else{
                    cout << "The " << raid[i].getType() << " got caught in the trap, taking full damage" << endl;
                    raid[i].damage(dmg);
                }
            }
        }
    }
    else if(room.getStars() == 2){
        for(int i = 0; i < raid.size(); i++){
            if(raid[i].getIsDead() == false){
                if(raid[i].getEvasion() > pass*4){
                    cout << "The " << raid[i].getType() << " easily beat the trap, taking no damage" << endl;
                }
                else if(raid[i].getEvasion() > (pass*2)){
                    cout << "The " << raid[i].getType() << " beat the trap, taking half damage" << endl;
                    raid[i].damage(dmg);
                }
                else{
                    cout << "The " << raid[i].getType() << " got caught in the trap, taking full damage" << endl;
                    raid[i].damage((dmg*2));
                }
            }
        }
    }
    else if(room.getStars() == 3){
        for(int i = 0; i < raid.size(); i++){
            if(raid[i].getIsDead() == false){
                if(raid[i].getEvasion() > pass*5){
                    cout << "The " << raid[i].getType() << " easily beat the trap, taking no damage" << endl;
                }
                else if(raid[i].getEvasion() > (pass*3)){
                    cout << "The " << raid[i].getType() << " beat the trap, taking half damage" << endl;
                    raid[i].damage((dmg*1.5));
                }
                else{
                    cout << "The " << raid[i].getType() << " got caught in the trap, taking full damage" << endl;
                    raid[i].damage((dmg*3));
                }
            }
        }
    }

    return !existAdv(raid);
}

bool strSkillCheck(vector<Adventurer> &raid, Rooms room){
    int strTotal = 0;
    int dmg = 5;
    for(int i = 0; i < raid.size(); i++){
        if(raid[i].getIsDead() == false){
            strTotal += raid[i].getAttack();
        }
    }
    if(room.getStars() == 1){
        if(strTotal > 20){
            cout << "The adventuring party had a combined strength of " << strTotal << " and easily passed the skill check, taking no damage" << endl;
        }
        else if(strTotal > 5){
            cout << "The adventuring party had a combined strength of " << strTotal << " and passed the skill check, taking half damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg/2);
                }
            }
        }
        else{
            cout << "The adventuring party had a combined strength of " << strTotal << " and failed the skill check, taking full damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg);
                }
            }
        }
    }
    else if(room.getStars() == 2){
        if(strTotal > 25){
            cout << "The adventuring party had a combined strength of " << strTotal << " and easily passed the skill check, taking no damage" << endl;
        }
        else if(strTotal > 10){
            cout << "The adventuring party had a combined strength of " << strTotal << " and passed the skill check, taking half damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg);
                }
            }
        }
        else{
            cout << "The adventuring party had a combined strength of " << strTotal << " and failed the skill check, taking full damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg*2);
                }
            }
        }
    }
    else if(room.getStars() == 3){
        if(strTotal > 30){
            cout << "The adventuring party had a combined strength of " << strTotal << " and easily passed the skill check, taking no damage" << endl;
        }
        else if(strTotal > 15){
            cout << "The adventuring party had a combined strength of " << strTotal << " and passed the skill check, taking half damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg*1.5);
                }
            }
        }
        else{
            cout << "The adventuring party had a combined strength of " << strTotal << " and failed the skill check, taking full damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg*3);
                }
            }
        }
    }

    return !existAdv(raid);
}

bool magicSkillCheck(vector<Adventurer> &raid, Rooms room){
    int magicTotal = 0;
    int dmg = 5;
    for(int i = 0; i < raid.size(); i++){
        if(raid[i].getIsDead() == false){
            magicTotal += raid[i].getMagic();
        }
    }
    if(room.getStars() == 1){
        if(magicTotal > 12){
            cout << "The adventuring party had a combined magic of " << magicTotal << " and easily passed the skill check, taking no damage" << endl;
        }
        else if(magicTotal > 4){
            cout << "The adventuring party had a combined magic of " << magicTotal << " and passed the skill check, taking half damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg/2);
                }
            }
        }
        else{
            cout << "The adventuring party had a combined magic of " << magicTotal << " and failed the skill check, taking full damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg);
                }
            }
        }
    }
    else if(room.getStars() == 2){
        if(magicTotal > 16){
            cout << "The adventuring party had a combined magic of " << magicTotal << " and easily passed the skill check, taking no damage" << endl;
        }
        else if(magicTotal > 8){
            cout << "The adventuring party had a combined magic of " << magicTotal << " and passed the skill check, taking half damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg);
                }
            }
        }
        else{
            cout << "The adventuring party had a combined magic of " << magicTotal << " and failed the skill check, taking full damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg*2);
                }
            }
        }
    }
    else if(room.getStars() == 3){
        if(magicTotal > 20){
            cout << "The adventuring party had a combined magic of " << magicTotal << " and easily passed the skill check, taking no damage" << endl;
        }
        else if(magicTotal > 12){
            cout << "The adventuring party had a combined magic of " << magicTotal << " and passed the skill check, taking half damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg*1.5);
                }
            }
        }
        else{
            cout << "The adventuring party had a combined magic of " << magicTotal << " and failed the skill check, taking full damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg*3);
                }
            }
        }
    }

    return !existAdv(raid);
}

bool dexSkillCheck(vector<Adventurer> &raid, Rooms room){
    int dexTotal = 0;
    int dmg = 5;
    for(int i = 0; i < raid.size(); i++){
        if(raid[i].getIsDead() == false){
            dexTotal += raid[i].getEvasion();
        }
    }
    if(room.getStars() == 1){
        if(dexTotal > 12){
            cout << "The adventuring party had a combined evasion of " << dexTotal << " and easily passed the skill check, taking no damage" << endl;
        }
        else if(dexTotal > 4){
            cout << "The adventuring party had a combined evasion of " << dexTotal << " and passed the skill check, taking half damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg/2);
                }
            }
        }
        else{
            cout << "The adventuring party had a combined evasion of " << dexTotal << " and failed the skill check, taking full damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg);
                }
            }
        }
    }
    else if(room.getStars() == 2){
        if(dexTotal > 16){
            cout << "The adventuring party had a combined evasion of " << dexTotal << " and easily passed the skill check, taking no damage" << endl;
        }
        else if(dexTotal > 8){
            cout << "The adventuring party had a combined evasion of " << dexTotal << " and passed the skill check, taking half damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg);
                }
            }
        }
        else{
            cout << "The adventuring party had a combined evasion of " << dexTotal << " and failed the skill check, taking full damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg*2);
                }
            }
        }
    }
    else if(room.getStars() == 3){
        if(dexTotal > 20){
            cout << "The adventuring party had a combined evasion of " << dexTotal << " and easily passed the skill check, taking no damage" << endl;
        }
        else if(dexTotal > 12){
            cout << "The adventuring party had a combined evasion of " << dexTotal << " and passed the skill check, taking half damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg*1.5);
                }
            }
        }
        else{
            cout << "The adventuring party had a combined evasion of " << dexTotal << " and failed the skill check, taking full damage" << endl;
            for(int i = 0; i < raid.size(); i++){
                if(raid[i].getIsDead() == false){
                    raid[i].damage(dmg*3);
                }
            }
        }
    }

    return !existAdv(raid);
}

void purgeMobs(vector<Adventurer> &raid){
    for(int i = 0; i < raid.size();){
        if(raid[i].getType() == "Slime" || raid[i].getType() == "Goblin" || raid[i].getType() == "Skeleton"){
            raid.erase(raid.begin() + i);
        }
        else{
            i++;
        }
        
    }
}

bool runCombat(vector<Adventurer> &initiative){
    bool allAdvDead = false;
    bool allMobsDead = false;
    int spot = 0;
    int inSize = initiative.size();

    while(allAdvDead == false && allMobsDead == false){
        if(initiative[spot%inSize].getIsDead() == false){
            cout << "\033[1;32mInitiative:\033[0m" << endl;
            for(int i = 0; i < initiative.size(); i++){
                if(initiative[i].getIsDead() == false){
                    cout << initiative[i].print() << endl;
                }
            }

            system("read");

            if(initiative[spot%inSize].getType() == "Warrior"){
                int attSpot = 0;

                if(existMob(initiative)){
                    attSpot = findFirstMob(initiative);
                    cout << "The level " << initiative[spot%inSize].getLevel() << " " << initiative[spot%inSize].getType() << " attacked the level " << 
                    initiative[attSpot].getLevel() << " " << initiative[attSpot].getType() << endl;
                    if((rand()%100 + 1) <= initiative[attSpot].getEvasion()){
                        cout << initiative[attSpot].getType() << " dodged the attack" << endl;
                    }
                    else if((rand()%100 + 1) <= initiative[attSpot].getDefense()){
                        cout << initiative[attSpot].getType() << " blocked the attack" << endl;
                    }
                    else{
                        initiative[attSpot].damage(initiative[spot%inSize].getAttack());
                    }
                }
            }
            else if(initiative[spot%inSize].getType() == "Rogue"){
                int attSpot = 0;

                if(existMob(initiative)){
                    attSpot = findFirstMob(initiative);
                    cout << "The level " << initiative[spot%inSize].getLevel() << " " << initiative[spot%inSize].getType() << " attacked the level " << 
                    initiative[attSpot].getLevel() << " " << initiative[attSpot].getType() << endl;
                    if((rand()%100 + 1) <= initiative[attSpot].getEvasion()){
                        cout << initiative[attSpot].getType() << " dodged the attack" << endl;
                    }
                    else if((rand()%100 + 1) <= initiative[attSpot].getDefense()){
                        cout << initiative[attSpot].getType() << " blocked the attack" << endl;
                    }
                    else{
                        initiative[attSpot].damage(initiative[spot%inSize].getAttack());
                    }
                }
            }
            else if(initiative[spot%inSize].getType() == "Wizard"){
                int attSpot = 0;

                if(existMob(initiative)){
                    attSpot = findFirstMob(initiative);
                    cout << "The level " << initiative[spot%inSize].getLevel() << " " << initiative[spot%inSize].getType() << " attacked the level " << 
                    initiative[attSpot].getLevel() << " " << initiative[attSpot].getType() << endl;
                    if((rand()%100 + 1) <= initiative[attSpot].getEvasion()){
                        cout << initiative[attSpot].getType() << " dodged the attack" << endl;
                    }
                    else if((rand()%100 + 1) <= initiative[attSpot].getDefense()){
                        cout << initiative[attSpot].getType() << " blocked the attack" << endl;
                    }
                    else{
                        initiative[attSpot].damage(initiative[spot%inSize].getAttack());
                    }
                }
            }
            else if(initiative[spot%inSize].getType() == "Slime"){
                int attSpot = 0;

                if(existAdv(initiative)){
                    attSpot = findFirstAdv(initiative);
                    cout << "The level " << initiative[spot%inSize].getLevel() << " " << initiative[spot%inSize].getType() << " attacked the level " << 
                    initiative[attSpot].getLevel() << " " << initiative[attSpot].getType() << endl;
                    if((rand()%100 + 1) <= initiative[attSpot].getEvasion()){
                        cout << initiative[attSpot].getType() << " dodged the attack" << endl;
                    }
                    else if((rand()%100 + 1) <= initiative[attSpot].getDefense()){
                        cout << initiative[attSpot].getType() << " blocked the attack" << endl;
                    }
                    else{
                        initiative[attSpot].damage(initiative[spot%inSize].getAttack());
                    }
                }
            }
            else if(initiative[spot%inSize].getType() == "Goblin"){
                int attSpot = 0;

                if(existAdv(initiative)){
                    attSpot = findFirstAdv(initiative);
                    cout << "The level " << initiative[spot%inSize].getLevel() << " " << initiative[spot%inSize].getType() << " attacked the level " << 
                    initiative[attSpot].getLevel() << " " << initiative[attSpot].getType() << endl;
                    if((rand()%100 + 1) <= initiative[attSpot].getEvasion()){
                        cout << initiative[attSpot].getType() << " dodged the attack" << endl;
                    }
                    else if((rand()%100 + 1) <= initiative[attSpot].getDefense()){
                        cout << initiative[attSpot].getType() << " blocked the attack" << endl;
                    }
                    else{
                        initiative[attSpot].damage(initiative[spot%inSize].getAttack());
                    }
                }
            }
            else if(initiative[spot%inSize].getType() == "Skeleton"){
                int attSpot = 0;

                if(existAdv(initiative)){
                    attSpot = findFirstAdv(initiative);
                    cout << "The level " << initiative[spot%inSize].getLevel() << " " << initiative[spot%inSize].getType() << " attacked the level " << 
                    initiative[attSpot].getLevel() << " " << initiative[attSpot].getType() << endl;
                    if((rand()%100 + 1) <= initiative[attSpot].getEvasion()){
                        cout << initiative[attSpot].getType() << " dodged the attack" << endl;
                    }
                    else if((rand()%100 + 1) <= initiative[attSpot].getDefense()){
                        cout << initiative[attSpot].getType() << " blocked the attack" << endl;
                    }
                    else{
                        initiative[attSpot].damage(initiative[spot%inSize].getAttack());
                    }
                }
            }
        }

        if(existMob(initiative) == false || existAdv(initiative) == false){
            if(existAdv(initiative) == false){
                allAdvDead = true;
            }
            else if(existMob(initiative) == false){
                allMobsDead = true;
            }
        }
        spot++;
    }
    return allAdvDead;
}

bool slimeCombat(vector<Adventurer> &raid, Rooms room){
    Gang g;
    Party p;

    Adventurer slime1;
    Adventurer slime2;
    Adventurer slime3;

    switch(room.getStars()){
        case 1:
            slime1 = g.getSlimeLvlOne();

            raid.push_back(slime1);
            break;

        case 2:
            slime1 = g.getSlimeLvlTwo();
            slime2 = g.getSlimeLvlTwo();

            raid.push_back(slime1);
            raid.push_back(slime2);
            break;

        case 3:
            slime1 = g.getSlimeLvlThree();
            slime2 = g.getSlimeLvlThree();
            slime3 = g.getSlimeLvlThree();

            raid.push_back(slime1);
            raid.push_back(slime2);
            raid.push_back(slime3);
            break;
    }
    cout << "Your " << room.getStars() << " level " << room.getStars() << " slimes attack the adventuring party\n" << endl;

    for(int i = 0; i < raid.size(); i++){
        for(int j = i; j < raid.size(); j++){
            if(raid[i].getEvasion() < raid[j].getEvasion()){
                Adventurer temp = raid[i];
                raid[i] = raid[j];
                raid[j] = temp;
            }
        }
    }
    return runCombat(raid);
}

bool goblinCombat(vector<Adventurer> &raid, Rooms room){
    Gang g;
    Party p;

    Adventurer goblin1;
    Adventurer goblin2;
    Adventurer goblin3;

    switch(room.getStars()){
        case 1:
            goblin1 = g.getGoblinLvlOne();

            raid.push_back(goblin1);
            break;

        case 2:
            goblin1 = g.getGoblinLvlTwo();
            goblin2 = g.getGoblinLvlTwo();

            raid.push_back(goblin1);
            raid.push_back(goblin2);
            break;

        case 3:
            goblin1 = g.getGoblinLvlThree();
            goblin2 = g.getGoblinLvlThree();
            goblin3 = g.getGoblinLvlThree();

            raid.push_back(goblin1);
            raid.push_back(goblin2);
            raid.push_back(goblin3);
            break;
    }
    cout << "Your " << room.getStars() << " level " << room.getStars() << " slimes attack the adventuring party\n" << endl;

    for(int i = 0; i < raid.size(); i++){
        for(int j = i; j < raid.size(); j++){
            if(raid[i].getEvasion() < raid[j].getEvasion()){
                Adventurer temp = raid[i];
                raid[i] = raid[j];
                raid[j] = temp;
            }
        }
    }
    return runCombat(raid);
}

bool skeletonCombat(vector<Adventurer> &raid, Rooms room){
    Gang g;
    Party p;

    Adventurer skeleton1;
    Adventurer skeleton2;
    Adventurer skeleton3;

    switch(room.getStars()){
        case 1:
            skeleton1 = g.getSkeletonLvlOne();

            raid.push_back(skeleton1);
            break;

        case 2:
            skeleton1 = g.getSkeletonLvlTwo();
            skeleton2 = g.getSkeletonLvlTwo();

            raid.push_back(skeleton1);
            raid.push_back(skeleton2);
            break;

        case 3:
            skeleton1 = g.getSkeletonLvlThree();
            skeleton2 = g.getSkeletonLvlThree();
            skeleton3 = g.getSkeletonLvlThree();

            raid.push_back(skeleton1);
            raid.push_back(skeleton2);
            raid.push_back(skeleton3);
            break;
    }
    cout << "Your " << room.getStars() << " level " << room.getStars() << " slimes attack the adventuring party\n" << endl;

    for(int i = 0; i < raid.size(); i++){
        for(int j = i; j < raid.size(); j++){
            if(raid[i].getEvasion() < raid[j].getEvasion()){
                Adventurer temp = raid[i];
                raid[i] = raid[j];
                raid[j] = temp;
            }
        }
    }
    return runCombat(raid);
}

void runRoom(vector<Adventurer> &raid, Rooms dungeon[5], int &loot){
    bool gg;
    for(int i = 0; i < 5; i++){
        if(dungeon[i].getType() != ""){
            cout << "\n\033[1;36m" << dungeon[i].print() << "\033[0m\n";
        }
        if(dungeon[i].getType().find("Trap") != std::string::npos){
            if(dungeon[i].getType().find("Boulder") != std::string::npos){
                gg = strTrap(raid, dungeon[i]);
            }
            else if(dungeon[i].getType().find("Magic") != std::string::npos){
                gg = magicTrap(raid, dungeon[i]);
            }
            else if(dungeon[i].getType().find("Fall") != std::string::npos){
                gg = dexTrap(raid, dungeon[i]);
            }
        }
        else if(dungeon[i].getType().find("Combat") != std::string::npos){
            if(dungeon[i].getType().find("Slime") != std::string::npos){
                gg = slimeCombat(raid, dungeon[i]);
            }
            else if(dungeon[i].getType().find("Goblin") != std::string::npos){
                gg = goblinCombat(raid, dungeon[i]);
            }
            else if(dungeon[i].getType().find("Skeleton") != std::string::npos){
                gg = skeletonCombat(raid, dungeon[i]);
            }
            purgeMobs(raid);
        }
        else if(dungeon[i].getType().find("Skill") != std::string::npos){
            if(dungeon[i].getType().find("Stone") != std::string::npos){
                gg = strSkillCheck(raid, dungeon[i]);
            }
            else if(dungeon[i].getType().find("Magic") != std::string::npos){
                gg = magicSkillCheck(raid, dungeon[i]);
            }
            else if(dungeon[i].getType().find("Parkour") != std::string::npos){
                gg = dexSkillCheck(raid, dungeon[i]);
            }
        }
        else if(dungeon[i].getType().find("Empty") != std::string::npos){
            cout << "Empty" << endl;
        }

        if(gg){
            cout << "\n\033[1;35mYour dungeon successfully fended off all the invading adventurers\033[0m\n";
            break;
        }
    }
    if(!gg){
        int yoink = 0;
        for(int i = 0; i < raid.size(); i++){
            if(raid[i].getIsDead() == false){
                yoink += raid[i].getLevel();
            }
        }
        cout << "\n\033[1;35mYour dungeon failed to fended off all the invading adventurers\033[0m\n";
        cout << "They took \033[1;93m" << yoink << "\033[0m of your loot\n";
        loot -= yoink;
    }
    system("read");
}

void tutorial(){
    Adventurer a;
    Party p;
    Rooms r;
    AllRooms ar;

    int loot = 10;
    int rounds = 1;

    Rooms dungeon[5];
    vector<Adventurer> raid;

    Rooms tutOp1;
    Rooms tutOp2;
    Rooms tutOp3;

    Adventurer advOp1;
    Adventurer advOp2;
    Adventurer advOp3;

    clearScreen();


    cout << "Welcome to the tutorial\n" << endl;
    cout << "In this game there are " << totalRooms << " rooms which you can mix and mash to make your dungeon and defend your loot" << endl;
    cout << "Howewver, adventureres know where loot is and they are after yours! So you'll need to defend it." << endl;
    cout << "There are four main types of rooms:" << endl;
    cout << "   - Trap" << endl;
    cout << "   - Combat" << endl;
    cout << "   - Skill Check" << endl;
    cout << "   - Empty\n" << endl;
    cout << "Trap rooms are well traps... there are different kinds that some adventurers are better at and some are worse at" << endl;
    cout << "Combat rooms put the adventuring party against some of your minions" << endl;
    cout << "Skill Check rooms compare the total stats of the adventuring party against a check" << endl;
    cout << "Empty rooms... well I'm sure there's a reason for them" << endl;
    cout << "Each type of room has \033[1;93mthree\033[0m variations:" << endl;
    cout << "   - Strength" << endl;
    cout << "   - Magic" << endl;
    cout << "   - Dexterity" << endl;
    cout << "Now pick your first room!\n" << endl;

    //cout << "The rooms are:" << endl;
    //ar.showAllRooms();

    tutOp1 = ar.getRoomLvlOne();
    tutOp2 = ar.getRoomLvlOne();
    tutOp3 = ar.getRoomLvlOne();

    roomWork(dungeon, tutOp1, tutOp2, tutOp3);

    cout << "Good Job! Now your dungeon looks like:" << endl;

    cout << "Your dungeon looks like:" << endl;
    for(int i = 0; i < 5; i++){
        if(dungeon[i].getType() == ""){
            cout << "\033[1;32m" << i + 1 << ". \033[0m_____";
        }
        else{
            cout << "\033[1;32m" << i + 1 << ". \033[0m\033[4m" << dungeon[i].getType() << "\033[0m";
        }
        cout << "      ";
    }
    cout << endl << endl;

    advOp1 = p.getAdvLvlOne();
    raid.push_back(advOp1);

    cout << "Oh look! Here comes a " << advOp1.print() << "\nlet's see what your dungeon can do!\n" << endl;

    runRoom(raid, dungeon, loot);

    cout << endl << endl << "Adventuring Party: " << endl;

    for(int i = 0; i < raid.size(); i++){
        cout << raid[i].print() << endl;
    }
}

void dungeonMakerGame(){
    Adventurer a;
    Party p;
    Rooms r;
    AllRooms ar;

    int loot = 10;
    int rounds = 1;

    Rooms dungeon[5];

    Rooms tutOp1;
    Rooms tutOp2;
    Rooms tutOp3;

    Adventurer advOp1;
    Adventurer advOp2;
    Adventurer advOp3;

    clearScreen();


    cout << "Welcome \033[1;91mLord\033[0m to \033[1;96myour\033[0m very own \033[1;93mdungeon\033[0m!" << endl;
    cout << "It does seem a little bland in here now that I'm getting a better look at things. How about you get a room!" << endl;

    cout << endl << endl;

    while(loot > 0 && rounds < 6){
        vector<Adventurer> raid;

        clearScreen();

        cout << "\033[1;93mRound: " << rounds << "         Loot: " << loot << "\033[0m\n\n";

        cout << "Your dungeon looks like:" << endl;
        for(int i = 0; i < 5; i++){
            if(dungeon[i].getType() == ""){
                cout << "\033[1;32m" << i + 1 << ". \033[0m_____";
            }
            else{
                cout << "\033[1;32m" << i + 1 << ". \033[0m\033[4m" << dungeon[i].getType() << "\033[0m";
            }
            cout << "      ";
        }
        cout << endl << endl;

        switch(rounds){
            case 1:
                tutOp1 = ar.getRoomLvlOne();
                tutOp2 = ar.getRoomLvlOne();
                tutOp3 = ar.getRoomLvlOne();

                advOp1 = p.getAdvLvlOne();

                raid.push_back(advOp1);
                break;
            case 2:
                tutOp1 = ar.getRoomLvlOne();
                tutOp2 = ar.getRoomLvlOne();
                tutOp3 = ar.getRoomLvlTwo();

                advOp1 = p.getAdvLvlOne();
                advOp2 = p.getAdvLvlTwo();

                raid.push_back(advOp1);
                raid.push_back(advOp2);
                break;
            case 3:
                tutOp1 = ar.getRoomLvlOne();
                tutOp2 = ar.getRoomLvlTwo();
                tutOp3 = ar.getRoomLvlTwo();

                advOp1 = p.getAdvLvlOne();
                advOp2 = p.getAdvLvlTwo();
                advOp3 = p.getAdvLvlTwo();

                raid.push_back(advOp1);
                raid.push_back(advOp2);
                raid.push_back(advOp3);
                break;
            case 4:
                tutOp1 = ar.getRoomLvlTwo();
                tutOp2 = ar.getRoomLvlTwo();
                tutOp3 = ar.getRoomLvlThree();

                advOp1 = p.getAdvLvlTwo();
                advOp2 = p.getAdvLvlTwo();
                advOp3 = p.getAdvLvlThree();

                raid.push_back(advOp1);
                raid.push_back(advOp2);
                raid.push_back(advOp3);
                break;
            case 5:
                tutOp1 = ar.getRoomLvlThree();
                tutOp2 = ar.getRoomLvlThree();
                tutOp3 = ar.getRoomLvlThree();

                advOp1 = p.getAdvLvlThree();
                advOp2 = p.getAdvLvlThree();
                advOp3 = p.getAdvLvlThree();

                raid.push_back(advOp1);
                raid.push_back(advOp2);
                raid.push_back(advOp3);
                break;
            default:
                cout << "Something is wrong" << endl;
                break;
        }

        roomWork(dungeon, tutOp1, tutOp2, tutOp3);

        cout << "Watch out a\n";
        for(int i = 0; i < raid.size(); i++){
            cout << raid[i].print() << "\n\n";
        }
        cout <<  "has arrived to your dungeon in search of loot.\n";

        runRoom(raid, dungeon, loot);

        rounds++;
    }

    if(loot > 0){
        cout << "Congrats you won with \033[1;93m" << loot << " \033[0mloot\n";
    }
    else{
        cout << "You Lost on round \033[1;93m" << rounds << "\033[0m\n";
    }
}

int main(){
    srand(time(0));

    Party p;
    Gang g;

    string choice;
    bool choiceWork = false;

    cout << "Welcome!" << endl;
    while(choiceWork == false){
        cout << "1. Tutorial" << endl;
        cout << "2. Play" << endl;
        cin >> choice;
        if(choice == "1"){
            choiceWork = true;
            tutorial();
        }
        else if(choice == "2"){
            choiceWork = true;
            dungeonMakerGame();
        }
    }
}