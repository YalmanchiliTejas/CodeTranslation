#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100005

int h, w, c, d;
char a[10][10];
bool flag;

int main()
{
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
            if(a[i][j] == '#' && !flag){
                c = j;
                if(j < d){
                    flag = true;
                }
            }
        }
        d = c;
        c = 0;
    }
    if(!flag)printf("Possible\n");
    else printf("Impossible\n");

    return 0;
}
