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




int main(){
    string s;
    cin>>s;
    ll a;
    cin>>a;
    stack<ll> S;
    S.push(s[0]-'0');
    for(int i=1;i<s.size();i+=2){
        if(s[i]=='+'){
            S.push(s[i+1]-'0');
        }
        else{
            ll k=S.top(); S.pop();
            S.push(k*(s[i+1]-'0'));
        }
    }
    ll cul1=0;
    while(!S.empty()){cul1+=S.top(); S.pop();}
    ll cul2=s[0]-'0';
    for(int i=1;i<s.size();i+=2){
        if(s[i]=='+'){cul2+=s[i+1]-'0';}
        else{cul2*=s[i+1]-'0';}
    }
    if(cul1==cul2){
        cout<<(a==cul1?"U":"I")<<endl;
    }
    else{
        cout<<(a==cul1?"M":(a==cul2?"L":"I"))<<endl;
    }
    
    

    return 0;
}

