/*
Writer: SPD_9X2
https://atcoder.jp/contests/arc073/tasks/arc073_c

全体の最大値と、最小値は必ず4つ中に含まれる
最大を必ず赤に割り振るとする

(1)最小が最大とペアでないとき、→自由な方における
(2)ペアの時、→青にしか置けない

ありうる分け方は2つ
(A)最小を赤にすると決めた時
    青の最大値を最小化して、最小値を最大化するのがよさそう？

(B)最小を青にするとき
    →赤の最小値を最大化、青の最大値を最小化するのが良い
    →貪欲に大きい方を赤&小さい方を青に選んでいけばよい

問題は(A)の時か…

青には、最小と最大の余り物は必ず含まれる。
また、残りのペアの内、最小値の最大 <= 青最大 　最大値の最小>=青最小
は必ず満たされる。


尺取り法！！
で、Nこのペアから1つづつ取るときの最大と最小の差の最小値を求められる

x>yにしておこう
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n,m) for(int (i)=(n);(i)<(m);(i)++)
#define rrep(i,n,m) for(int (i)=(n);(i)>(m);(i)--)
using ll = long long;

int main(){

    ll N;
    cin >> N;

    ll maxind = 0, minind = 0;
    ll x,y,t;
    vector<vector<ll>> xy(N,vector<ll> (2,0));

    rep(i,0,N){
        cin >> x >> y;

        if (x < y){
            t = x;
            x = y;
            y = t;
        }

        xy[i][0] = x;
        xy[i][1] = y;

        if (x > xy[maxind][0]) maxind = i;
        if (y < xy[minind][1]) minind = i;
    }

    ll rmin = 10000000000;
    ll bmax = 0;

    rep(i,0,N){

        x = xy[i][0];
        y = xy[i][1];

        if ((i==maxind) && (i==minind)){
            continue;
        }else if (i==maxind){
            bmax = max(bmax,y);
            continue;
        }else if (i==minind){
            rmin = min(rmin,x);
            continue;
        }
        
        rmin = min(rmin,max(x,y));
        bmax = max(bmax,min(x,y));

    }

    ll ans = ((xy[maxind][0]-rmin) * (bmax-xy[minind][1]));

    if (maxind != minind){

        ll side_R = (xy[maxind][0] - xy[minind][1]);

        ll apnum = 0;
        vector<ll> aplis(N,0);
        vector<vector<ll>> wait(0,vector<ll> (2,0));

        rep(i,0,N){

            if (i==maxind){
                wait.push_back({xy[i][1],i});
            }else if (i==minind){
                wait.push_back({xy[i][0],i});
            }else{
                wait.push_back({xy[i][0],i});
                wait.push_back({xy[i][1],i});
            }
        }

        vector<vector<ll>> q(0,vector<ll> (2,0));
        sort(wait.begin(),wait.end());
        
        ll find = 0;

        rep(i,0,wait.size()){

            ll num = wait[i][0];
            ll ind = wait[i][1];

            if (aplis[ind] == 0){
                apnum++;
            }

            aplis[ind] ++;
            q.push_back({num,ind});

            if (apnum==N){

                while (aplis[q[find][1]] > 1){
                    aplis[q[find][1]] -= 1;
                    find++;
                }

                ans = min(ans, side_R*(q[q.size()-1][0] - q[find][0]) );
            }
        }
    }

    cout << ans << endl;
}