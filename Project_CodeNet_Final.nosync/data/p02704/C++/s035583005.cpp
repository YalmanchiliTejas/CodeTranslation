#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(),(a).end()
#define SZ(a) (int)(a).size()
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define iFOR(i, a, b) for(int i=(a); i>=(b); --i)
#define make_unique(a) sort(all((a))), (a).resize(unique(all((a)))-(a).begin())

using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long UL; // ULLONG_MAX, %llu
typedef unsigned int UI; //UINT_MAX %u
typedef double DD;
typedef long double LD;
typedef pair<LL,LL> PLL;
typedef pair<DD,DD> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;

void termi(){
    printf("-1");
    exit(0);
}
const int N = 505;
bool lockrow[64][N], lockcol[64][N];
UL ans[N][N], tmp[64][N][N];
int cmd[N][2], cnt_row[64][N], cnt_col[64][N];
UL val[N][2];
void eval(int k, int i, int j, int ch){
    cnt_row[k][i]+=ch; cnt_col[k][j]+=ch;
}
int main(){
    int n;
    scanf("%d",&n);
    FOR(i,0,1){
        FOR(j,1,n){
            scanf(" %d",&cmd[j][i]);
        }
    }
    FOR(i,0,1){
        FOR(j,1,n){
            scanf(" %llu",&val[j][i]);
        }
    }
    memset(tmp, -1, sizeof tmp); // undetermine
    // Fundamental determination
    int bit_max = 63;
    FOR(k, 0, bit_max){
        FOR(i, 1, n){
            int a = ((val[i][0]>>k)&1);
            if(cmd[i][0] != a){
                lockrow[k][i] = true;
                FOR(j, 1, n){
                    if(tmp[k][i][j] == -1) tmp[k][i][j] = a;
                    else if(tmp[k][i][j] != a) termi();
                    if(!a) eval(k,i,j,1);
                }
            }
            int b = ((val[i][1]>>k)&1);
            if(cmd[i][1] != b){
                lockcol[k][i] = true;
                FOR(j, 1, n){
                    if(tmp[k][j][i] == -1) tmp[k][j][i] = b;
                    else if(tmp[k][j][i] != b) termi();
                    if(!b) eval(k,j,i,1);
                }
            }
        }
        FOR(i, 1, n){
            FOR(j, 1, n){
                if(lockrow[k][i] || lockcol[k][j]) continue;
                if(cmd[i][0] == cmd[j][1]) tmp[k][i][j] = cmd[i][0];
                else tmp[k][i][j] = 0;
                if(!tmp[k][i][j]) eval(k, i, j, 1);
            }
        }
        FOR(i, 1, n){
            if(lockrow[k][i] || cmd[i][0] == 0) continue;
            int ch = 0;
            FOR(j, 1, n){
                if(tmp[k][i][j]) ch = 1;
            }
            if(ch) continue;
            FOR(j, 1, n){
                if(lockcol[k][j] || cnt_col[k][j] == 1) continue;
                tmp[k][i][j] = 1; eval(k, i, j, -1);
                break;
            }
        }
        FOR(j, 1, n){
            if(lockcol[k][j] || cmd[j][1] == 0) continue;
            int ch = 0;
            FOR(i, 1, n){
                if(tmp[k][i][j]) ch = 1;
            }
            if(ch) continue;
            FOR(i, 1, n){
                if(lockrow[k][i] || cnt_row[k][i] == 1) continue;
                tmp[k][i][j] = 1; eval(k, i, j, -1);
                break;
            }
        }
        FOR(i, 1, n){
            FOR(j, 1, n){
                ans[i][j] |= ((UL)tmp[k][i][j]<<k);
            }
        }
    }
    FOR(i, 1, n){
        UL res[2];
        res[0] = ULLONG_MAX; res[1] = 0;
        FOR(j, 1, n) res[0] &= ans[i][j], res[1] |= ans[i][j];
        if(res[cmd[i][0]] != val[i][0]) termi();
        res[0] = ULLONG_MAX, res[1] = 0;
        FOR(j, 1, n) res[0] &= ans[j][i], res[1] |= ans[j][i];
        if(res[cmd[i][1]] != val[i][1]) termi();
    }
    FOR(i, 1, n){
        FOR(j, 1, n){
            printf("%llu ",ans[i][j]);
        }
        printf("\n");
    }
	return 0;
}
/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
