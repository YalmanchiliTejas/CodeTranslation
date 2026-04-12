#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define INF 1e7
int main(void){
    int n;
    string s;
    cin >> n;
    string ret;
    map<char, int> buf;
    for(char c='a'; c<='z'; c++){
        buf[c] = INF;
    }
    for(int i=0; i<n; i++){
        cin >> s;
        for(char c='a'; c<='z'; c++){
            buf[c] = min(buf[c], int(count(s.begin(), s.end(), c)));
        }
    }
    for(char c='a'; c<='z'; c++){
        for(int i=0; i<buf[c]; i++){
            ret += c;
        }
    }
    cout << ret << endl;
}