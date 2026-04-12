#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <stdlib.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define PI 3.14159265358979
typedef long long int ll;

const double pi=3.1415;
ll absc(ll a,ll b){return (a-b>0?a-b:b-a);
}
ll mini(ll a,ll b){return (a>b?b:a);}
ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	return (a%b?gcd(a%b,b):b);
}
int main()
{
   string a;
   cin>>a;
   cout<<(a=="AAA"||a=="BBB"?"No":"Yes");
}
