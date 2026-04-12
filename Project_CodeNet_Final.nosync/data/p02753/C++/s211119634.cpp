#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define pb push_back
typedef long long ll;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;

int main(){
    vector<char> s(3);
    
    rep(i,3){
        cin >> s.at(i);

    }
    if(s.at(0)==s.at(1)&&s.at(0)==s.at(2))
        cout << "No" << endl;
        else
        {
            cout << "Yes" << endl;
        
        }
        

}