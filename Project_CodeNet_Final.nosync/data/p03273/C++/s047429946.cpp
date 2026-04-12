#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define all(a)  a.begin(), a.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))


#define forr(i,n) for(i=0; i<n; i++)
#define whilee(i,t) while(i!=t)
//#define pb(x) push_back(x);

//sort(A.begin(),A.end());
//binary_search(A.begin(),A.end(),x);
//reverse(A.begin(), A.end());
//cout << *max_element(A.begin(), A.end());
//cout << *min_element(A.begin(), A.end());
//accumulate(A.begin(), A.end(), 0);
//next_permutation(A.begin(), A.end());
//prev_permutation(A.begin(), A.end());



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //vector <int> A;
    //deque <int> A;
    //queue <int> A;
    //stack <int> A;
    //set <int> A;
    //map <int,int> A;
    //pair <int,int> A ;
    //vector <pair <int,int>> A ;
    //string S, T;
    int i, j, k, a, b, c, h, w, l, m, n, p, q, r, s, t, x, y, z, cnt=0;
    cin>>h>>w;
    char A[h][w];
    forr(i,h)
    {
        forr(j,w)
        {
            cin>>A[i][j];
        }
    }
    forr(i,h)
    {
        cnt=0;
        forr(j,w)
        {
            if(A[i][j]=='.')
            {
                cnt++;
            }
        }
        if(cnt==w)
        {
            forr(j,w)
            {
                A[i][j]='0';
            }
        }
    }
    forr(i,w)
    {
        cnt=0;
        forr(j,h)
        {
            if(A[j][i]=='.' || A[j][i]=='0')
            {
                cnt++;
            }
        }
        if(cnt==h)
        {
            forr(j,h)
            {
                A[j][i]='0';
            }
        }
    }
    forr(i,h)
    {
        x=0;
        forr(j,w)
        {
            if(A[i][j]!='0')
            {
                x=1;
                cout<<A[i][j];
            }
        }
        if(x==1)
        {
            cout<<endl;
        }
    }
    return 0;
}

