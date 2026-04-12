#include <iostream>
#include<map>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

int main(){
    
    int n;
    int m[20]={0};
    int ans=0,mm=0;
    cin >> n;
    rep(i,n){
        cin >> m[i];
    }
    
    rep(i,n){
        if(m[i]>=mm){
            ans++;
            mm=m[i];
        }
    }
    
    cout << ans<<endl;
    
    return 0;
}