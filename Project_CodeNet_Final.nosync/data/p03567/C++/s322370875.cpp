#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int>   vi;
typedef vector<long long> vll;
typedef vector<pair<int,int> > vii;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pq priority_queue
#define mii map<int,int>
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d %d",&x,&y)
#define sf3(x,y,z) scanf("%d %d %d",&x,&y,&z)
int inf = (1e9) + 7;
int mod = 998244353;





int main(){

    string s;
    cin >> s;



    for (int i = 0; i < s.size()-1; ++i)
    {
        if(s[i] == 'A' and s[i+1] == 'C')
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}   