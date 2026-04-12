#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int p[2000];

int main() {
    int n,m;
    string s;
    while(cin>>n>>m, n|m) {
        memset(p, -1, sizeof(p));
        for(int i=1; i<=n; ++i) p[i-1] = i;
        int now = 0;
        for(int i=0; i<m; ++i) {
            //cout<<"now "<<now<<endl;
            cin>>s;
            if((i+1)%3 == 0 && (i+1)%5 == 0) {
                if(s != "FizzBuzz") p[now] = -1;
            }else if((i+1)%3 == 0) {
                if(s != "Fizz") p[now] = -1;
            }else if((i+1)%5 == 0) {
                if(s != "Buzz") p[now] = -1;
            }else{
                if(atoi(s.c_str()) != i+1) p[now] = -1;
            }

            for(int i=1; i<=n; ++i) {
                if(p[(now+i+n)%n] > 0) {
                    now = (now+i+n)%n;
                    break;
                }
                if(i==n) {
                    p[now] = now+1;
                    break;
                }
            }
        }

        bool first = true;
        for(int i=0; i<n; ++i) {
            if(p[i] > 0) {
                if(!first) printf(" ");
                printf("%d", p[i]);
                first = false;
            }
        }
        puts("");
    }
}