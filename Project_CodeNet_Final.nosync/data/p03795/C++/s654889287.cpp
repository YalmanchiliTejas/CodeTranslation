#include<iostream>
#include<math.h>
#include <algorithm>
#include<float.h>
#include <limits>
#include <vector> 
#include <numeric>

#define rep(i,a,n) for(ll int (i) = (a);(i) < (n);(i)++)
#define urep(i,a,n) for(ll int (i) = (a);(i) > (n);(i)--)
#define MOD 1000000007
#define ll long long

using namespace::std;

int jo(ll int x, ll int y){
	ll int jhogeo = 1;
	rep(jinto,0,y) jhogeo=jhogeo*x;
	return jhogeo;
}


int main(){
int N;
  cin>>N;
  cout<<N*800-(N/15)*200;

      
}
// int *p = new int[N];

// vector<vector<int>> 変数名(左の個数, vector<int>(右の個数));

//
