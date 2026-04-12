#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

vector<ll> totals;
vector<ll> patties;

ll saiki(ll N, ll X)
{
    //レベル0なら1を返す
    if(N == 0)
    {
        return 1;
    }
    //現在の(レベル-1)での位置をカウントし、その区切りより右のレベルはその層数をそのまま使う
    if(X == totals.at(N))
    {
        //左端
        return patties.at(N);
    }else if(X > totals.at(N - 1) + 2){
        //左のレベルN - 1のどこか
        ll nextX = X - totals.at(N - 1) - 2;
        return patties.at(N - 1) + saiki(N - 1, nextX) + 1;
    }else if(X == totals.at(N - 1) + 2){
        //真ん中
        return patties.at(N - 1) + 1;
    }else if(X > 1){
        //右のレベルN - 1 のどこか
        return saiki(N - 1, X - 1);
    }else if(X == 1){
        //右端
        return 0;        
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    totals = vector<ll>(N + 1);//レベルNのバーガー全体の層数
    patties = vector<ll>(N + 1);//レベルNのパティの数
    totals.at(0) = 1;
    patties.at(0) = 1;
    for (int i = 1; i <= N; i++)
    {
        totals.at(i) = totals.at(i - 1) * 2 + 3;
        patties.at(i) = patties.at(i - 1) * 2 + 1;
    }
    cout << saiki(N, X) << endl;
    return 0;
}
