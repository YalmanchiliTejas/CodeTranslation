#include <bits/stdc++.h>
using namespace std;
char s[55];
int cnt[26], cnt2[26];
int main(){
    for(int i=0;i<26;i++) cnt2[i] = 1e9;
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%s", s+1);
        memset(cnt, 0, sizeof(cnt));
        int l = strlen(s+1);
        for(int j=1;j<=l;j++) cnt[s[j]-'a']++;
        for(int j=0;j<26;j++) cnt2[j] = min(cnt2[j], cnt[j]);
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<cnt2[i];j++) printf("%c", i+'a');
    }
    printf("\n");
}