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
#define P pair<int,int>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

int main(){
    
    string s;
    char c;
    int n,k;
    cin >> n;
    cin >> s;
    cin>> k;
    c=s[k-1];
    rep(i,n){
        if(s[i]!=c)s[i]='*';
    }
    
    cout << s<<endl;
    
    return 0;
}
