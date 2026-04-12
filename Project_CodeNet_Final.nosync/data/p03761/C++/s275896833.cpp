#include <bits/stdc++.h>
using namespace std;

int main(){
        vector <int > ans (26,100);
        int n=0;
        cin >> n;
        for (int i=0;i<n;i++){
                vector <int > res (26);
                string s="";
                cin >> s;
                for (int j=0;j<s.size();j++) res[s[j]-'a']++;
                for (int i=0;i<26;i++) ans[i]=min(ans[i],res[i]);
        }
        for (int i=0;i<26;i++){
                char curr='a'+i;
                string temp (ans[i],curr);
                cout << temp;
        }
}
