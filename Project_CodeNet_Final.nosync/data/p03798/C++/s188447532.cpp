#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

void zenbubatsu(){}
char animals1[100000] = {};
char animals2[100000] = {};
char animals3[100000] = {};
char animals4[100000] = {};
string s;
int n;
bool ok[4] = {true,true,true,true};
string sw(char now, char adj, char ans){
    if(now == 'S'){
        if(ans == 'o'){
            return adj == 'S' ? "S" : "W";
        } else {
            return adj == 'S' ? "W" : "S";
        }
    } else {
        if(ans == 'x'){
            return adj == 'S' ? "S" : "W";
        } else {
            return adj == 'S' ? "W" : "S";
        }
    }
}
bool match(string sw){
    for(int i=0;i<n;i++){
        if((s[i] == 'o') != ((sw[(i+n-1)%n] == sw[(i+1) % n]) == (sw[i] == 'S'))){
            return false;
        }
    }
    return true;
}
bool trySW(string str){
    for(int i=2;i<n;i++){
        str += sw(str[i-1],str[i-2],s[i-1]);
    }
    if(match(str)){
        cout << str << endl;
        return true;
    }
    return false;
}
int main(){
    cin >> n >> s;
    string animals="SS";
    if(trySW("SS") || trySW("SW") || trySW("WS")||trySW("WW")){
        return 0;
    }
    cout << -1 << endl;
}
