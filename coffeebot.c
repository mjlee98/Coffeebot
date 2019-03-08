#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int cupStock;
int shotStock;
char name[100];
char yesno[32];
int cups;
int shots;
float totalPrice;

bool twoArg(int numArg){
  if(numArg == 1){
    printf("No arguments. System terminating.\n");
    return false;
  }
  else if(numArg == 2){
    printf("Not enough arguments. System terminating.\n");
    return false;
  }
  else if(numArg == 3){
    return true;
  }
  else{
    printf("Too many arguments. System terminating.\n" );
    return false;
  }
}

bool intArg(char *inp[]){
  if(sscanf(inp[1],"%i", &cupStock) != 1 && sscanf(inp[2],"%i", &shotStock) != 1){
    printf("invalid cup and shot stock\n");
    return false;
  }
  else if(sscanf(inp[1],"%i", &cupStock) != 1){
    printf("invalid cup stock\n");
    return false;
  }
  else if(sscanf(inp[2],"%i", &shotStock) != 1){
    printf("invalid shot stock\n");
    return false;
  }
  return true;
}

int main(int argc, char *argv[])
{
  if(!twoArg(argc)){
    return 0;
  }
  if(!intArg(argv)){
    return 0;
  }
  if(cupStock < 1 && shotStock < 1){
    printf("Negative supply chain. System terminating\n");
    return 0;
  }
  else if(cupStock < 1){
    printf("Negative supply of coffee cups. System terminating\n");
    return 0;
  }
  else if(shotStock < 1){
    printf("Negative supply of coffee shots. System terminating\n");
    return 0;
  }
  printf("Hello, what's your name?  ");
  gets(name);
  printf("Would you like to order some coffee, ");
  printf("%s?(y/n) ",name);
  gets(yesno);

  while(strcmp(yesno,"n") != 0 && strcmp(yesno,"y") != 0){
    printf("Invalid response. Try again.\n");
    printf("Would you like to order some coffee, ");
    printf("%s?(y/n) ",name);
    gets(yesno);
  }
  if(strcmp(yesno,"n") == 0){
    printf("Come back next time, %s.\n",name);
    return 0;
  }

  printf("Great! Let's get started.\n\nOrder selection\n---------------\n\n" );
  printf("There is %d coffee cup in stock and each costs $2.00.\n",cupStock);
  printf("There is %d coffee shot in stock and each costs $1.00.\n\n",shotStock);
  printf("How many cups of coffee would you like? ");
  scanf("%d", &cups);
  if(cups == 0){
    printf("No cups, no coffee. Goodbye.\n");
    return 0;
  }
  else if(cups < 0){
    printf("Does not cumpute. System terminating.\n");
    return 0;
  }
  else if(cups > cupStock){
    printf("Not enough stock. Come back later.\n");
    return 0;
  }
  int shotTrack[cups];
  for(int a = 0; a<cups; a++){
    printf("How many coffee shots in cup %d? ",a+1);
    scanf("%d", &shots);
    while(shots<0){
      printf("Does not compute. Try again.\n");
      printf("How many coffee shots in cup %d? ",a+1);
      scanf("%d",&shots);
    }
    while(shots>shotStock){
      if(shotStock == 1){
        printf("There is only 1 coffee shot left. Try again.\n");
      }
      else{
        printf("There are only %d coffee shots left. Try again.\n",shotStock);
      }
        printf("How many coffee shots in cup %d? ",a);
        scanf("%d",&shots);
    }
    shotTrack[a] = shots;
    shotStock -= shots;
  }
  printf("\nOrder summary\n-------------\n\n");
  for(int a = 0; a<cups;a++){
    float price=2+1*shotTrack[a];
    totalPrice += price;
    if(shotTrack[a] == 1){
      printf("Cup %d has 1 shot and will cost $%0.2f\n",a+1,price);
    }
    else{
      printf("Cup %d has %d shots and will cost $%0.2f\n",a+1,shotTrack[a],price);
    }
  }
  printf("\n%d coffees to purchase.\n",cups);
  printf("Purchase prise is $%0.2f\n",totalPrice);
  printf("Proceed to payment? (y/n)");
  gets(yesno);

  while(strcmp("n",yesno) != 0 && strcmp("y",yesno) != 0){
    printf("Invalid response. Try again.");
    printf("Proceed to payment? (y/n)");
    gets(yesno);
  }
  if(strcmp("n",yesno) == 0){
    printf("Come back next time,%s.\n",name );
    return 0;
  }
  return 0;
}
