#include<bits/stdc++.h>
using namespace std;
inline int_fast64_t read(){int_fast64_t x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void Main(){
    string ans = "NO";
    int X = read();
    if (X == 3 || X == 5 || X == 7) ans = "YES";
    printf("%s\n", ans.c_str());
}
int main(){cin.tie(nullptr);ios::sync_with_stdio(false);Main();return 0;}