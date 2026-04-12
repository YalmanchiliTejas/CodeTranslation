#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10 , M = 5e5+10 ,  MOD = 1e9+7;
const int OO = 0x3f3f3f3f;
const double EPS = 1e-3;
#define M_PI 3.14159265358979323846
#define clr(arr,val) memset(arr , val , sizeof (arr))
#define loop(i,n) for(int i = 0;i < int(n);i++)
#define rloop(i,n) for(int i = int(n)-1;i >= 0;i--)
#define range(i,a,b) for(int i = int(a);i <= int(b);i++)
#define pb push_back
#define F first
#define S second
#define all(v) ((v).begin()) , ((v).end())
#define sz(v)  ((int)((v).size()))
typedef pair <int,int> pii ;
typedef vector < pii > vii ;
typedef vector < int > vi;
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
 

int n, m;
char grid[105][105];
bool row[105] , col[105];



int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
	

    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < n ; ++i)
        scanf("%s", grid[i]);

   
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j)
            if(grid[i][j] == '#')
                row[i] = 1 , col[j] = 1;
    }
   
    bool f = 0;
    for(int i = 0 ; i < n ; ++i){
        if(row[i]){
            for(int j = 0 ; j < m ; ++j){
                if(col[j])
                    printf("%c",grid[i][j]);
            }
            puts("");
        }
    }



    
    return 0;
}