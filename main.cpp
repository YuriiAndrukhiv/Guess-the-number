#include <stdlib.h>
#include <time.h>
#include <iostream>

int level = 1;
int const NUMBER_OF_ATTEMPTS = 10;

char menu()
{
  std::cout << "[Level " << level << " ] Would like to play?" << std::endl;
  std::cout << "[p] - play" << std::endl;
  std::cout << "[l] - select level" << std::endl;
  std::cout << "[q] - quit" << std::endl;

  char choose;
  std::cin >> choose;
  if (choose != 'p' && choose != 'l' && choose != 'q')
  {
    do
    {         
      std::cout << "use only options - 'p', 'l', 'q'" << std::endl;
      std::cin >> choose;
      std::cout << std::endl;
    }
    while (choose != 'p' && choose != 'l' && choose != 'q');
  }
  
  return choose; 
}

void play()
{
  srand (time(0));
  int number;
  number = rand() % (100 * level) + 1;
  int guess;
  for(int i = 1; i <= NUMBER_OF_ATTEMPTS; i++)
  {
    std::cout << "Enter your estimate: ";
    std::cin >> guess;
    if (i == NUMBER_OF_ATTEMPTS)
    {
      std::cout << "You lose!" << std::endl;
      return;
    }
    else if (guess > number)
    {
      std::cout << "Less" << std::endl;
    }
    else if(guess < number)
    {
      std::cout << "Greater" << std::endl;
    }
    else
    { 
      std::cout << "You win!" << std::endl;
      return;
    }
  }
}

void setLevel()
{
  std::cout << "Enter number of level (from 1 to 10): ";
  std::cin >> level;
  while(level > 10 || level <= 0)
  {
    std::cout << "use only 1 - 10" << std::endl;
    std::cin >> level;
  }
}

int main()
{
  char option;
  do
  {
    option = menu();
    if(option == 'p')
    {
      play();
    }
    else if(option == 'l')
    {
      setLevel();
    }
    else 
    {
      exit(0);
    }
  }
  while(option != 'q');
  
  system ("pause");
}

