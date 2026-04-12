#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<deque>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>

#define rep(i, n) for(int i=0;i<n;i++)

typedef int long long ll;
using namespace std;
typedef pair<int, int> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
static const int MAX = 100;
static const int INF = (1 << 23);

int main() {

    set<char> a1;
    set<char> a2;
    char al1[15]={'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
    char al2[11]={'Y','U','I','O','P','H','J','K','L','N','M'};
    rep(i,15){
        a1.insert(al1[i]);
    }
    rep(i,11){
        a2.insert(al2[i]);
    }

    string s;
    while(true){
        cin>>s;
        if(s.size()==1&&s[0]=='#')break;
        vector<int> v;
        rep(i,s.size()){
            if(a1.find(s[i])!=a1.end()){
                v.push_back(1);
            }else{
                v.push_back(2);
            }
        }

        int ans=0;
        for(int i=0;i<s.size()-1;i++){
           // cout<<v[i]<<endl;
            if(v[i]!=v[i+1])ans++;
        }


        cout<<ans<<endl;



    }


    return 0;
}

