#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,q,T,k;

ll xm,ym;
ll xm2,ym2;

ll i1, i2;

vector<ll> X;
vector<ll> Y;

vector<ll> X2;
vector<ll> Y2;
vector<ll> ind;

bool comp(ll i, ll j){
return Y2[i] < Y2[j];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;
    ll ma = 0;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        X.push_back(a);
        Y.push_back(b);
        if(max(a,b) > ma){
            ma = max(a,b);
            i1 = c1;
        }
    }

    if(n == 1){
        cout << "0\n";
    }
    else{
        ll mi = big*big;
        for(ll c1 = 0; c1 < n; c1++){
            if(min(X[c1] , Y[c1]) < mi && c1 != i1){
                mi = min(X[c1] , Y[c1]);
                i2 = c1;
            }
        }

        ll ans = big*big;

        xm = max(X[i1],Y[i1]);
        if(xm == X[i1]){
            ym = Y[i1];
        }
        else{
            ym = X[i1];
        }

        ym2 = min(X[i2],Y[i2]);
        if(ym2 == X[i2]){
            xm2 = Y[i2];
        }
        else{
            xm2 = X[i2];
        }

        ll xmin,xmax,ymin,ymax;
        xmin = min(xm,xm2);
        xmax = max(xm,xm2);
        ymin = min(ym,ym2);
        ymax = max(ym,ym2);

        for(ll c1 = 0; c1 < n; c1++){
            if(c1 != i1 && c1 != i2){
                ll x = max(X[c1],Y[c1]);
                ll y = min(X[c1],Y[c1]);
                xmin = min(xmin,x);
                xmax = max(xmax,x);
                ymin = min(ymin,y);
                ymax = max(ymax,y);

            }
        }

        ans = min(ans , (xmax-xmin) * (ymax-ymin));


        ll temp = xm2;
        xm2 = ym2;
        ym2 = temp;
        xmin = min(xm,xm2);
        xmax = max(xm,xm2);
        ymin = min(ym,ym2);
        ymax = max(ym,ym2);

        for(ll c1 = 0; c1 < n; c1++){

            if(c1 != i1 && c1 != i2){
                ind.push_back(ind.size());
                X2.push_back(max(X[c1],Y[c1]));
                Y2.push_back(min(X[c1],Y[c1]));
            }

        }

        sort(all(ind),comp);

        for(ll c1 = 0; c1 < n-2; c1++){
            ll x = X2[c1];
            ll y = Y2[c1];
            ymax = max(ymax, y);
        }

        ll oldy = ymin;

        for(ll c1 = 0; c1 < n-2; c1++){
            ymin = min(Y2[ind[c1]],oldy);
            ans = min(ans, (xmax-xmin) * (ymax-ymin));
            ymax = max(ymax, X2[ind[c1]]);
            oldy = min(oldy , X2[ind[c1]]);
        }

        cout << ans << "\n";

    }

    return 0;
}
