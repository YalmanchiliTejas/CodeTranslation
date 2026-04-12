#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
#define PIL pair<int,LL>
#define PLI pair<LL,int>
#define PIII pair<int,PII>
#define PLL pair<LL,LL>
#define PLII pair<LL,PII>
#define VI vector<int>
#define VVI vector<VI>
#define VL vector<LL>
#define VVL vector<VL>
#define VPII vector<PII>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define all(x) x.begin(),x.end()
#define watch(x) cout<<(#x)<<" = "<<(x)<<'\n'
#define mset(a,v) memset(a,v,sizeof(a))
#define setp(x) cout<<fixed<<setprecision(x)
#define EPS 0.00000000001
#define PI acos(-1)
#define loop(i,b,n) for(int i=b;i<n;++i)
#define rev_loop(i,b,n) for(int i=b;i>=n;--i)
using namespace std;

const int MOD = 1e18;
const LL MX = 1e9;
const LL INF = 1e9;

LL n, x, m;

int main()
{
    //ofstream out("output.txt");
    //ifstream in("input.txt");
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>x>>m;
    ULL m_val[m];
    loop(i,0,m) m_val[i] = INF;

    ULL ans = x;
    --n;
    VL vec;

    while(n)
    {
        //watch(x);
        if(m_val[x] == INF)
        {
            --n;
            m_val[x] = (x * x) % m;
            ans += m_val[x];
            vec.PB(x);
            //watch(m_val[x]);
            x = m_val[x];
        }
        else
        {
            int id = -1, sz = vec.size();
            ULL sum = 0;

            loop(i,0,sz)
            {
                if(vec[i] == x) {id = i;}
                if(id != -1) sum += m_val[vec[i]];
            }

            //watch(sum);

            int l = sz - id;
            LL n1 = n / l, m1 = n % l;
            //watch(n1); watch(m1);

            ans += (sum * n1);
            while(m1--)
            {
                ans += m_val[vec[id]]; ++id;
            }

            break;
        }
    }

    cout<<ans<<'\n';

    return 0;
}
