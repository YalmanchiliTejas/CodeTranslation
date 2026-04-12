#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> piipi;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

char s[55];
int cnt[26], cnt2[26];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<26;i++) cnt[i] = 1e9;
    for(int i=1;i<=n;i++){
        scanf("%s", s);
        int l = strlen(s);
        memset(cnt2, 0, sizeof(cnt2));
        for(int i=0;i<l;i++){
            cnt2[s[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            cnt[i] = min(cnt[i], cnt2[i]);
        }
    }   
    for(int i=0;i<26;i++){
        for(int j=0;j<cnt[i];j++) printf("%c", i+'a');
    }
}