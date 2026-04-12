#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;	

const int nmax = 100;
int scmax , scmin;

int cal(int score[], int count)
{
   long sum = 0; 
   bool cmax = false, cmin = false;
   for (int i = 0; i < count; i++) 
   {	
    if ((score[i] == scmin) && (cmin == false))
       {cmin = true; 
        continue;}
    if ((score[i] == scmax) && (cmax == false)) 
       {cmax = true; 
	continue;}
    sum += score[i];
   }
   return(sum/(count-2));	
}

int main(void) 
{
do{
  int n;
  cin >> n;
  if ( n == 0 ) break;
  int score[nmax];
  scmax = 0; 
  scmin = 1000;
  for (int i = 0; i < n; i++)
     {
	cin >> score[i];	
	if (scmax < score[i]) scmax = score[i];
	if (scmin > score[i]) scmin = score[i];
     }
  cout << cal(score,n) << endl; 
} while(1);
}