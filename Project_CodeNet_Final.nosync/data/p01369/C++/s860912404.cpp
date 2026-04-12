#include <bits/stdc++.h>
using namespace std;

string S;
int ans,now;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<char> left={'q','w','e','r','t'
                        ,'a','s','d','f','g'
                        ,'z','x','c','v','b'};
    while(cin >> S,S!="#"){
        ans=0;
        for (int i=0;i<S.size();++i){
            int L=count(left.begin(),left.end(),S[i]);
            if (i&&now!=L) ++ans;
            now=L;
        }
        cout << ans << endl;
    }
}
