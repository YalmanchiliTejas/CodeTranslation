 #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define INPUT()              freopen("input.txt", "r", stdin)
    #define OUTPUT()             freopen("output.txt", "w", stdout)
    #define F                    first
    #define S                    second
//Templatefunctions
    template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x%y);}
    template <class T> T euclideanDistance(T x1 , T x2 , T y1 , T y2){return sqrt(( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ));}
    template <class T> T digitSum(T n){T sum = 0;while(n > 0)sum += n % 10,n /= 10;return sum;}
//datatypes
    typedef long long int ll;
    typedef unsigned long long int ull;
    typedef long double ld;
//constants
    const double INF = 1e+9;
    const double INFLL = 1e+18;
    const double EPS = 1e-9;
    const double PI = acos(-1);
    const int knightDir[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1},{-1,-2},{1,-2}};
           //const int dx[]={0,0,0,1,1,1,-1,-1,-1};
           //const int dy[]={-1,0,1,-1,0,1,-1,0,1};
    const int dx[] = {0 , 1 , 0 , -1};
    const int dy[] = {1 , 0 , -1 , 0};
//helpers
    //#define MOD         1000000007LL
    #define MAX         2000005
    const ll MOD = 1000000000 + 7;
    //int arr[10000005];
    char str[MAX+10];
    int dp[MAX],bad[MAX];
//Global Variables
    //int dp[MAX],n;
    std::map<int,int>::iterator it;
     signed main()
    {
//        int t;
//        scanf("%d",&t);
//        int x = 2;
//        while(t--)
//        {
//        }
        char arr[105][105];
        int h ,w;
        scanf("%d%d",&h,&w);
        for(int i = 0 ; i < h ; i++)
        {
            scanf("%s",arr[i]);
        }

        for(int i = 0 ; i < h ; i++)
        {
            int flag = 1;
            for(int j = 0 ; j < w ; j++)
            {
                if(arr[i][j] == '.' || arr[i][j] == '@')
                {
                    continue;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }

            if(flag)
            {
                for(int j = 0 ; j < w ; j++)
                {
                    arr[i][j] = '@';
                }
            }
        }
        for(int i = 0 ; i < w ; i++)
        {
            int flag = 1;
            for(int j = 0 ; j < h ; j++)
            {
                if(arr[j][i] == '.' || arr[j][i] == '@')
                {
                    continue;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }

            if(flag)
            {
                for(int j = 0 ; j < h ; j++)
                {
                    arr[j][i] = '@';
                }
            }
        }

        for(int i = 0 ; i < h ; i++)
        {
            int flag = 1;
            for(int j = 0 ; j < w ; j++)
            {
                if(arr[i][j] == '@')flag++;
                if(arr[i][j] != '@')printf("%c",arr[i][j]);
            }
            if(flag < h)printf("\n");

        }
    }
//
