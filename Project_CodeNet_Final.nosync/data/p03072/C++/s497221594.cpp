#include<iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int H[N];
  int i,j,k=1;
  for(i=0;i<N;i++)cin >> H[i];
    
    for(i=1;i<N;i++)
    {
        for(j=i-1;j>=0;j--)
        {
          if(H[j]>H[i])goto damedesita;
        }
        k++;
        damedesita:
        continue;
    }
    cout << k;
  
  return 0;
}