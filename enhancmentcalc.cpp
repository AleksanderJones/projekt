#include <random>
#include <iostream>
#include <string>
#include <unistd.h>


auto choosearm(std::string prompt) -> int
{
std::cout << prompt << "\n 1 for weapon, 2 for armour: ";
    auto n = std::string{};
    std::getline(std::cin, n);
    return std::stoi(n);
    
}
auto main() -> int
{
    //RNG PART
    std::random_device generator;
 std::mt19937 rng(generator());
 std::uniform_int_distribution<std::mt19937::result_type> enchprobability(1,100);
 ////////////////////////////////////////////////////////////////////////////////
    //MAIN CODE
    std::cout <<"///////////////////////////////////////\n" "Welcome to the enhancing simulator! \n" << "/////////////////////////////////////// \n";
    std::cout <<"this simulator is based on a real videogame with toned down probabilities.\n" ;
    std::cout <<"You can enhance either weapons or armour, and there are a total of 5 levels.\n Remember you start at 1.\n";
     ask:
     std::cout <<"Do you wish to enhance a weapon or armor? \n";
     int const itempicked = choosearm("");
     while (true)
     {

         if(itempicked <3){
             std::cout << "Good choice!\n";
             break;
         }
         std::cout << "Pick again!\n";
         goto ask;
     }
     std::cout <<"Starting...\n";
     
     int weapsucceedcount = 1;
     int armorsucceedcount = 1;
     int weapfailcount = 0;
     int armorfailcount = 0;
     if (itempicked<=1){
     duo:
     

    const  int rng1 = enchprobability(rng);
     //WEAPON
    if (weapsucceedcount = 1,rng1<=50)
    {
       
        std::cout <<" Level 2 Enhancement succeeded.\n";
         std::cout << "Rolled: " << rng1 <<"\n";
        weapsucceedcount++;
    } else{std::cout << "Enhancement to level 2 Failed, Try Again.\n";
        weapfailcount++;
         std::cout << "Rolled: " << rng1 <<"\n";
        goto duo;
        }
    tri:
     const int rng2 = enchprobability(rng);
    if (weapsucceedcount=2, rng2<=44)
    {
        std::cout <<" Level 3 Enhancement succeeded.\n";
        std::cout << "Rolled: " << rng2 <<"\n";
        weapsucceedcount++;
        
    }else{
std::cout <<"Enhancement to level 3 Failed, Try Again.\n";
        weapfailcount++;
         std::cout << "Rolled: " << rng2 <<"\n";
        goto duo;
    }
    tet:
const int rng3= enchprobability(rng);
    if (weapsucceedcount=3, rng3<=21)
    {
        std::cout <<" Level 4 Enhancement succeeded.\n";
          std::cout << "Rolled: " << rng3 <<"\n";
        weapsucceedcount++;
    }else{
        std::cout <<"Enhancement to level 4 Failed, Try Again.\n";
       weapfailcount++;
         std::cout << "Rolled: " << rng3 <<"\n";
        goto tri;

    }

    const int rng4 = enchprobability(rng);
    if (weapsucceedcount=4, rng4<=3)
    {
        std::cout <<" Level 5 Congrats you have successfully enhanced to the highest level.\n";
         std::cout << "Rolled: " << rng4 <<"\n";
         std::cout << "The amount of tries it took to hit level 5 on weapons was: " << weapfailcount << "\n";
        goto ask;
    }else{
        std::cout <<"Enhancement to level 5 Failed, so close. Try Again.\n";
        weapfailcount++;
         std::cout << "Rolled: " << rng4 <<"\n";
        goto tet;
    }
     }
    if (itempicked>=2){
      //armor
      armorduo:
       const  int rng1ar = enchprobability(rng);
      if (armorsucceedcount = 1,rng1ar<=75)
    {
       
        std::cout <<" Level 2 Enhancement succeeded.\n";
         std::cout << "Rolled: " << rng1ar <<"\n";
        armorsucceedcount++;
    } else{std::cout << "Enhancement to level 2 Failed, Try Again.\n";
        armorfailcount++;
         std::cout << "Rolled: " << rng1ar <<"\n";
        goto armorduo;
        }
    armortri:
     const int rng2ar = enchprobability(rng);
    if (armorsucceedcount=2, rng2ar<=44)
    {
        std::cout <<" Level 3 Enhancement succeeded.\n";
        std::cout << "Rolled: " << rng2ar <<"\n";
        armorsucceedcount++;
        
    }else{
        std::cout <<"Enhancement to level 3 Failed, Try Again.\n";
         std::cout << "Rolled: " << rng2ar <<"\n";
          armorfailcount++;
        goto armorduo;
    }
    armortet:
    const int rng3ar= enchprobability(rng);
    if (armorsucceedcount=3, rng3ar<=12)
    {
        std::cout <<" Level 4 Enhancement succeeded.\n";
          std::cout << "Rolled: " << rng3ar <<"\n";
        armorsucceedcount++;
    }else{std::cout <<"Enhancement to level 4 Failed, Try Again.\n";
         std::cout << "Rolled: " << rng3ar <<"\n";
          armorfailcount++;
        goto armortri;
    }
    const int rng4ar = enchprobability(rng);
    if (armorsucceedcount=4, rng4ar<=2)
    {
        std::cout <<" Level 5 Congrats you have successfully enhanced to the highest level.\n";
         std::cout << "Rolled: " << rng4ar <<"\n";
         std::cout << "The amount of tries it took to hit level 5 on armor was: " << armorfailcount << "\n";
        goto ask;
    }else{
        std::cout <<"Enhancement to level 5 Failed, so close. Try Again.\n";
         std::cout << "Rolled: " << rng4ar <<"\n";
          armorfailcount++;
        goto armortet;
    }
    }
    return 0;
    }
    
   
 
   

/*Plany na projekt:
1. Dodanie zbroi (DONE 13-01-2022)
2.Overhaul systemu żeby nie zaczynał od początku tylko zchodził o 1 poziom ulepszenia, oraz liczył ilość prób ulepszenia i dodawał stały % szansy na powodzenie.(ETA FEB 2022)
3. Datamine prawdziwych % z gry (Paywall/TBD ETA FEB 2022)
4. Całkowity overhaul systemu RNG.(ETA FEB 2022)
5. Podłączenie DB z wszystkimi danymi (DB ITW. ETA FEB 2022)
6.jakiekolwiek GUI. (TBD - IDK hard.)
7.Symulacja monte carlo. (TBD - level insane eta po sesji)



*/