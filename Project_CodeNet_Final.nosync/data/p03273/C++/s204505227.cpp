/* Murad Eynizade */

#include <bits/stdc++.h>
#define intt long long
#define FAST_READ ios_base::sync_with_stdio(0);cin.tie(0);
#define SIZE 100001
#define INF INT_MAX
#define F first
#define S second
#define in(a) scanf("%d",&a);
#define outn(a) printf("%d\n",&a);
#define outs(a) printf("%d ",&a);


using namespace std;



int main()
{
    FAST_READ;
    int n , m;
    cin>>n>>m;
    char a[n][m];
    int cor[n] , coc[m];
    memset(cor,0,sizeof(cor));
    memset(coc,0,sizeof(coc));
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<m;j++) {
            cin>>a[i][j];
            if (a[i][j] == '.') {
                cor[i]++;
                coc[j]++;
            }
        }
    }
    for (int i = 0;i<n;i++) {
        if (cor[i] == m)continue;
        for (int j = 0;j<m;j++) {
            if (coc[j] == n)continue;
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
