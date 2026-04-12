#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    string t = "qwertasdfgzxcvb";
    while(cin >> s, s!="#"){
        int ans = 0;
        int c = -1;
        for(int i = 0; i < s.size(); i++){
            int p = 0;
            for(int j = 0; j < t.size(); j++)if(s[i]==t[j])p = 1;
            if(c != p)ans++;
            c = p;
        }
        cout << ans-1 << endl;
    }
}

