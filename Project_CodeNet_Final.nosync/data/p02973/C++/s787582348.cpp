#include<bits/stdc++.h>
using namespace std;
inline int_fast64_t read(){int_fast64_t x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
inline string read_s(){string s="";char c=getchar();while(c<'!'||c>'~'){c=getchar();}while(c>='!'&&c<='~'){s+=c;c=getchar();}return s;}
void Main(){
    int N = read(), ans = 0;
    vector<int> A(N), B(N, -1);
    for (auto& a:A) {
        a = read();
    }
    int it;
    for (int i = 0; i<N; i++) {
        it = lower_bound(B.begin(), B.end(), A[i])-B.begin();
        B[it-1] = A[i];
    }
    for (auto b:B) {
        if (b != -1) ans++;
    }
    printf("%d\n", ans);
}
int main(){cin.tie(nullptr);ios::sync_with_stdio(false);Main();return 0;}