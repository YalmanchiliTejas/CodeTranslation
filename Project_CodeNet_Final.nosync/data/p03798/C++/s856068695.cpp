#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

ll n;
string s;
vector<ll> color;//狼:1 hituzi:0

bool cul(){
    for(int i=2;i<n;i++){
        color[i]=((ll)s[i-1]^color[i-1]^color[i-2]);
    }
    for(int i=0;i<n;i++){
        if(color[i]!=((ll)s[(i+n-1)%n]^color[(i+n-1)%n]^color[(i+n-2)%n])){return false;}
        if(color[i]!=((ll)s[(i+1)%n]^color[(i+1)%n]^color[(i+2)%n])){return false;}
    }
    return true;
}




int main(){
    cin>>n;
    cin>>s;
    color.resize(n);
    for(auto &I:s){
        if(I=='o'){I=0;}
        else{I=1;}
    }
    for(int i=0;i<2;i++){
        for(int t=0;t<2;t++){
            color[0]=i;
            color[1]=t;
            if(cul()){
                for(auto &I:color){cout<<(I?"W":"S");}
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<"-1"<<endl;
    
    
    return 0;
}
