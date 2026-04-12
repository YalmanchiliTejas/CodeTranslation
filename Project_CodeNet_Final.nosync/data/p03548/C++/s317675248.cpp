#include <iostream>
#include <string>
#include <vector>
#include <algorithm>]
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;

int main(){
ll x,y,z;cin>>x>>y>>z;
x-=z;
cout<<max(0ll,x/(y+z));

}