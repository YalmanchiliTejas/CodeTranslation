#include <stdio.h>

int main(){
  char campany_A = 'A';
  char campany_B = 'B';
  
  char stations[4];
  int isBusMoving = 0;
  int isStationA, isStationB;
  isStationA = isStationB = 0;
  
  scanf("%s", stations);
  for(int i = 0; i < sizeof(stations); i++){
    if(stations[i] == campany_A)
      isStationA = 1;
    else if(stations[i] == campany_B)
      isStationB = 1;
  }
  
  if(isStationA && isStationB)
    puts("Yes");
  else
    puts("No");
  
  return 0;
}