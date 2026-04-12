#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include<unordered_set>
#include<string.h>
#include<unordered_map>
#include<numeric>
#include<iomanip>
#include<string.h>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

#define FOR(i,N) for(int i=0;i<N;i++)

ll mod=1e9+7;
double EPS=1e-8;



int main(){
    string s;
    cin>>s;
    if(s.length()<2){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=1;i<s.length();i++){
        if(s[i-1]=='A'&&s[i]=='C'){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    
    
    return 0;
}
