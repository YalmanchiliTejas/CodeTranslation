#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    for(ll i = 0; i < 4; i++){
        vector<string> vp;
        if(i==0){vp.push_back("S"); vp.push_back("S");}
        if(i==1){vp.push_back("S"); vp.push_back("W");}
        if(i==2){vp.push_back("W"); vp.push_back("S");}
        if(i==3){vp.push_back("W"); vp.push_back("W");}
        for(ll j = 0; j < s.length()-1; j++){
            if(s[j]=='o' && vp[j]=="S" && vp[j+1]=="S") vp.push_back("S");
            if(s[j]=='o' && vp[j]=="W" && vp[j+1]=="S") vp.push_back("W");
            if(s[j]=='o' && vp[j]=="S" && vp[j+1]=="W") vp.push_back("W");
            if(s[j]=='o' && vp[j]=="W" && vp[j+1]=="W") vp.push_back("S");
            if(s[j]=='x' && vp[j]=="S" && vp[j+1]=="S") vp.push_back("W");
            if(s[j]=='x' && vp[j]=="W" && vp[j+1]=="S") vp.push_back("S");
            if(s[j]=='x' && vp[j]=="S" && vp[j+1]=="W") vp.push_back("S");
            if(s[j]=='x' && vp[j]=="W" && vp[j+1]=="W") vp.push_back("W");
            //cout << vp << endl;
        }
        vp.push_back(vp[1]);
        bool ok = true;
        /*for(ll j = 0; j < vp.size(); j++)
            cout << vp[j];
        cout << endl;*/
        //if(vp[0]!=vp[vp.size()-1]) ok = false;
        for(ll j = 1; j < vp.size()-1; j++){
            if(vp[j]=="S" && s[j-1]=='o' && vp[j-1]!=vp[j+1])
                ok = false;
            if(vp[j]=="S" && s[j-1]=='x' && vp[j-1]==vp[j+1])
                ok = false;
            if(vp[j]=="W" && s[j-1]=='o' && vp[j-1]==vp[j+1])
                ok = false;
            if(vp[j]=="W" && s[j-1]=='x' && vp[j-1]!=vp[j+1])
                ok = false;
        }
        if(vp[0]!=vp[vp.size()-2]) ok = false;
        //if(s.begin()!=s.end()) ok = false;
        if(ok==true){
            for(ll i = 1; i < vp.size()-1; i++)
                cout << vp[i];
            cout << endl;
            break;
        }
        if(ok==false && i==3)
            cout << -1 << endl;
    }
    return 0;
}
