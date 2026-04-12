#include<bits/stdc++.h>
using namespace std;
inline int_fast64_t read(){int_fast64_t x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
inline string read_s(){string s="";char c=getchar();while(c<'!'||c>'~'){c=getchar();}while(c>='!'&&c<='~'){s+=c;c=getchar();}return s;}
void Main(){
    int N = read();
    string S = read_s();
    int K = read();
    for (int i = 0; i<S.size(); i++) {
        if (S[i]==S[K-1]) putchar(S[i]);
        else putchar('*');
    }
    putchar('\n');
}
int main(){cin.tie(nullptr);ios::sync_with_stdio(false);Main();return 0;}