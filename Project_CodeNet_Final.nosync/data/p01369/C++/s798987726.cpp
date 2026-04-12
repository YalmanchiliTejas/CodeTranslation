#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int (i)=0;(i) < (N); (i)++)
#define all(V) V.begin(), V.end()
using i64 = long long;
using P = pair<int,int>;

const string byleft = "yhnujmikolp";
bool f(char c) {
    for(const char& l : byleft) {
        if(l == c) return true; 
    }
    return false;
}


int main(){
    string S;
    while(cin >> S, S != "#"){
        bool now = f(S[0]);
        int ans = 0;
        for(char& c : S){
            bool isLeft = false;
            for(const char& l : byleft){
                if(c == l) isLeft = true;
            }
            if(now != isLeft) ans++;
            now = isLeft;
        }

        cout << ans << endl;
    }
}

