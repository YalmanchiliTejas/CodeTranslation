#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <set>
#include <cmath>
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b+1;i++)
#define Per(i,b,a) for(int i=b;i>=a;i--)
int main(){
    string S;
    cin>>S;
    
    if( (S[0]==S[1]) && (S[1]==S[2])){
        cout<<"No"<<endl;
    }else cout<<"Yes"<<endl;
    return 0;
}