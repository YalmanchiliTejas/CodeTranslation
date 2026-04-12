#include <bits/stdc++.h>
#define for0(i,b) for(int i=0 ; i< b ;i++)
#define for1(i,b) for(int i=1 ; i<=b ;i++)
#define reps(i,a,b) for(int i=a ; i< b.length() ;i++)
typedef long long ll;
#define MOD 1000000007

using namespace std;




int main()
{
  char car;
  int tab[2]={0};

for (int i =0 ; i<3 ; i++ ){
  cin >> car ;
  if(car=='A')tab[0]++;
  else tab[1]++;
}
if(tab[0]==3 || tab[1]==3 ) {
  cout << "No" ;
  return 0 ;
}
cout <<"Yes";



  return 0 ;
}
