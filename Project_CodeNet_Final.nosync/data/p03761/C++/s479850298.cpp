#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<string> s(50);
    map<char, int> memo;
    for(int i=0; i<n; i++){
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
        char tmp;
        int cnt=0;
        map<char, int> dis;
        for(int j=0; j<s[i].length(); j++){
            if(dis.count(s[i][j])){
                dis[s[i][j]]++;
            }else{
                dis[s[i][j]]=1;
            }

        }
        for(int j=0; j<26; j++){
            if(!dis.count('a'+j)) dis['a'+j]=0;
            if(memo.count('a'+j)){
                memo['a'+j] = min(memo['a'+j], dis['a'+j]);
            }else{
                memo['a'+j] = dis['a'+j];
            }
        }
    }
    for(int i=0; i<26; i++){
        if(memo.count(i+'a')){
            for(int j=0; j<memo[i+'a']; j++){
                char tmp = 'a' + i;
                printf("%c", tmp);
            }
        }
    }
    printf("\n");
    return 0;

}