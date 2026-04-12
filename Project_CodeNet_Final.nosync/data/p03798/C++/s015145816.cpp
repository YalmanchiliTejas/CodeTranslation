#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N;
string s;
char a[100010];
char Other(char c){
    return (c=='S')?'W':'S';
}
bool Able(){
    for(ll i=1;i<N-1;i++){
        ll l=i-1;
        ll r=(i+1);
        if(a[i]=='S' ^ s[i]=='o'){
            a[i+1]=Other(a[i-1]);
        }else{
            a[i+1]=a[i-1];
        }
    }
    bool f1=(a[0]=='S'^s[0]=='o')^(a[1]==a[N-1]);
    bool f2=(a[N-1]=='S'^s[N-1]=='o')^(a[0]==a[N-2]);
    return f1 && f2;
}
int main(){
    cin>>N>>s;
    for(ll i=0;i<4;i++){
        a[0]=(i/2==0)?'S':'W';
        a[1]=(i%2==0)?'S':'W';
        if(Able()){
            for(ll i=0;i<N;i++) cout<<a[i];
            return 0;
        } 
    }
    cout<<-1;
    return 0;
}