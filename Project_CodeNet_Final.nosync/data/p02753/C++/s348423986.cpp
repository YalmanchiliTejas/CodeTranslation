#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PRECISION std::cout << std::fixed << std::setprecision(20);
  
using namespace std;
 
const ll inf = 1e17;
const ll N = 2e5+100;
const ll bits = 35;
const ll mod = 1e9+7;
const ld pi = 3.14159265358979323846;
 

int main(){
    FASTIO;
    PRECISION;

    ll a=0,b=0;

    string s;
    cin>>s;

    for(auto x: s){
        if(x=='A'){
            a++;
        }else{
            b++;
        }
    }

    if(a&&b){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }



    
}