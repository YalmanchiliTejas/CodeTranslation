#include<bits/stdc++.h>
using namespace std;
inline int_fast64_t read(){int_fast64_t x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void Main(){
    int N = read(), ans = 1;
    vector<int> H(N);
    for (auto &h:H) h = read();
    for (int i = 1; i<N; i++) {
        if(H[i]>=H[i-1]) ans++;
        H[i] = max(H[i],H[i-1]);
    }
    printf("%d\n", ans);
}
int main(){cin.tie(nullptr);ios::sync_with_stdio(false);Main();return 0;}