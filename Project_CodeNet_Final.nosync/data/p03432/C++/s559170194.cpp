#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 8000+10, inf = 1000111222;
const int max_m = 200+10;

const int md = 998244353;

const int N=(1ll<<14);

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=1ll*res*a%md;
        }
        n/=2;
        a=1ll*a*a%md;
    }
    return res;
}

int inv(int a)
{
    return bpow(a,md-2);
}

int neg(int a)
{
    if (a==0){
        return 0;
    }
    return (md-a);
}

int sum(int a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
    return a;
}

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

int mul(int a,int b)
{
    return 1ll*a*b%md;
}

int root=-1;
int rev_N=-1;

int pw[N];
int rpw[N];

void init()
{
    root = 227806;
//    for (root=2;;root++){
//        if (bpow(root,N)==1){
//            int cur=1;
//            bool ok=1;
//            for (int step=1;step<N;step++){
//                cur=mul(cur,root);
//                if (cur==1){
//                    ok=0;
//                    break;
//                }
//            }
//            if (ok){
//                cerr<<"root :: "<<root<<"\n";
//                break;
//            }
//        }
//    }

    pw[0]=1;
    for (int i=1;i<N;i++){
        pw[i]=mul(pw[i-1],root);
    }

    int rroot=inv(root);
    rpw[0]=1;
    for (int i=1;i<N;i++){
        rpw[i]=mul(rpw[i-1],rroot);
    }

    rev_N=inv(N);
}

void fft(int* a,int* pw)
{
    for (int i=0;i<N;i++){
        int r=0;
        for (int j=0;j<14;j++){
            if (i&(1ll<<j)){
                r|=(1ll<<(14-j-1));
            }
        }
        if (i<r){
            swap(a[i],a[r]);
        }
    }
    for (int i=1,pl=N/2;2*i<=N;i*=2,pl/=2){
        for (int j=0;j<N;j+=2*i){
            int cur=0;
            for (int k=j;k<j+i;k++){
                int L=a[k];
                int R=mul(pw[cur], a[k+i]);

                a[k]=sum(L,R);
                a[k+i]=sum(L,neg(R));

                cur+=pl;
            }
        }
    }
}

void make_fast_mult(int* a,int* b,int* c)
{
    if (root==-1){
        init();
    }
    fft(a,pw);
    fft(b,pw);
    for (int i=0;i<N;i++){
        c[i]=mul(a[i],b[i]);
    }
    fft(c,rpw);
    for (int i=0;i<N;i++){
        c[i]=mul(c[i],rev_N);
    }
}

const bool use_fft=1;

void make_mult(int* a,int* b,int* c)
{
    if (use_fft){
        make_fast_mult(a,b,c);
        return;
    }
    for (int i=0;i<2*max_n;i++){
        c[i]=0;
    }
    for (int i=0;i<max_n;i++){
        for (int j=0;j<max_n;j++){
            inc(c[i+j],mul(a[i],b[j]));
        }
    }
}

//namespace solve1 {
//
//    int c[max_n][max_n];
//    int dp[2][max_n];
//
//    int solve(int n,int m)
//    {
//        memset(c,0,sizeof(c));
//        memset(dp,0,sizeof(dp));
//
//        for (int i=0;i<max_n;i++){
//            c[i][0]=1;
//            for (int j=1;j<=i;j++){
//                c[i][j]=c[i-1][j]+c[i-1][j-1];
//                if (c[i][j]>=md){
//                    c[i][j]-=md;
//                }
//            }
//        }
//
//        int q1=0,q2=1;
//        for (int i=0;i<=n;i++){
//            dp[q1][i]=c[n][i];
//        }
//        for (int column=m;column>=1;column--){
//            for (int i=0;i<max_n;i++){
//                dp[q2][i]=0;
//            }
//            for (int opened=0;opened<=n;opened++){
//                // len == 0
//                inc(dp[q2][opened],dp[q1][opened]);
//
//                // len == 1
//                inc(dp[q2][opened], mul(opened,dp[q1][opened]));
//                if (opened){
//                    inc(dp[q2][opened-1], mul(opened,dp[q1][opened]));
//                }
//
//                // len >= 2
//                for (int take_l=0;take_l<2;take_l++){
//                    for (int take_r=0;take_r<2;take_r++){
//                        for (int len=2;len<=opened;len++){
//                            for (int close=0;close<=len-2 && close+take_l+take_r<=opened;close++){
//                                int cur_val = 1;
//                                cur_val = mul(cur_val, opened - len + 1);
//                                cur_val = mul(cur_val, c[len-2][close]);
//                                cur_val = mul(cur_val, dp[q1][opened]);
//                                inc(dp[q2][opened-close-take_l-take_r], cur_val);
//                            }
//                        }
//                    }
//                }
//            }
//
//            swap(q1,q2);
//        }
//        return dp[q1][0];
//    }
//}

//namespace solve2 {

    int f[max_n];
    int rf[max_n];

    int dp[2][max_n];
    int to_add1[max_n];
    int to_add3[max_n];

    int buf_A[N];
    int buf_B[N];
    int buf_C[N];

    int solve(int n,int m)
    {
        f[0]=1;
        for (int i=1;i<max_n;i++){
            f[i]=1ll*f[i-1]*i%md;
        }
        rf[max_n-1]=inv(f[max_n-1]);
        for (int i=max_n-2;i>=0;i--){
            rf[i]=1ll*rf[i+1]*(i+1)%md;
        }
        memset(dp,0,sizeof(dp));

        int q1=0,q2=1;
        for (int i=0;i<=n;i++){
            dp[q1][i]=1ll*f[n]*rf[n-i]%md*rf[i]%md;
        }

        auto do_magic_1=[&]()
        {
            for (int i=0;i<max_n;i++){
                to_add1[i]=0;
            }
            for (int i=0;i<N;i++){
                buf_A[i]=0;
                buf_B[i]=0;
            }
            for (int opened=2;opened<=n;opened++){
                buf_A[opened] = mul(opened - 1, dp[q1][opened]);
                buf_A[opened] = mul(buf_A[opened], f[opened-1]);

                // add magic2
                inc(buf_A[opened], neg(mul(f[opened-1], mul(opened-2, dp[q1][opened]))));
            }
            for (int close=0;close<=n-2;close++){
                buf_B[max_n-close-1] = rf[close+1];
            }
            make_mult(buf_A,buf_B,buf_C);
            for (int i=2;i<=n;i++){
                to_add1[i] = mul(buf_C[max_n-1 + i], rf[i-2]);
            }
        };

        auto do_magic_3=[&]()
        {
            for (int i=0;i<max_n;i++){
                to_add3[i]=0;
            }
            for (int i=0;i<N;i++){
                buf_A[i]=0;
                buf_B[i]=0;
            }
            for (int opened=2;opened<=n;opened++){
                buf_A[opened] = mul(f[opened-1], dp[q1][opened]);
            }
            for (int close=0;close<=n-2;close++){
                buf_B[max_n-close-1] = rf[close+2];
            }
            make_mult(buf_A,buf_B,buf_C);
            for (int i=3;i<=n;i++){
                to_add3[i] = mul(buf_C[max_n-1 + i], rf[i-3]);
            }
        };

        for (int column=m;column>=1;column--){
//            cerr<<"column :: "<<column<<"\n";
            for (int i=0;i<max_n;i++){
                dp[q2][i]=0;
            }

            do_magic_1();
            // process magic 1 2
            for (int take_l=0;take_l<2;take_l++){
                for (int take_r=0;take_r<2;take_r++){
                    int sum_takes=take_l+take_r;
                    for (int i=0;i<=n;i++){
                        if (i>=sum_takes){
                            inc(dp[q2][i-sum_takes],to_add1[i]);
                        }
                    }
                }
            }

            do_magic_3();
            // process magic 3
            for (int take_l=0;take_l<2;take_l++){
                for (int take_r=0;take_r<2;take_r++){
                    int sum_takes=take_l+take_r;
                    for (int i=0;i<=n;i++){
                        if (i>=sum_takes){
                            inc(dp[q2][i-sum_takes],to_add3[i]);
                        }
                    }
                }
            }

            for (int opened=0;opened<=n;opened++){
                // len == 0
                inc(dp[q2][opened],dp[q1][opened]);

                // len == 1
                inc(dp[q2][opened], mul(opened,dp[q1][opened]));
                if (opened){
                    inc(dp[q2][opened-1], mul(opened,dp[q1][opened]));
                }

                // len >= 2
                if (opened>=2){
                    auto process_kek=[&](){
//                        for (int i=0;i<max_n;i++){
//                            to_add[i]=0;
//                        }
//                        for (int close=0;close<=opened-2;close++){
//                            int a = mul(f[opened-1], mul(opened - 1, dp[q1][opened]));
//                            int b = rf[close+1];
//
//                            inc(to_add[opened-close], mul(rf[opened-close-2], mul(a,b)));
//                        }
//                        for (int close=0;close<=opened-2;close++){
//                            int a = neg(mul(f[opened-1], mul(opened-2, dp[q1][opened])));
//                            int b = rf[close+1];
//
//                            inc(to_add[opened-close], mul(rf[opened-close-2], mul(a,b)));
//                        }
//                        for (int close=0;close<=opened-3;close++){
//                            int a = mul(f[opened-1], dp[q1][opened]);
//                            int b = rf[close+2];
//
//                            inc(to_add[opened-close], mul(rf[opened-close-3], mul(a,b)));
//                        }
                    };


                    /// magic will do that
//                    for (int take_l=0;take_l<2;take_l++){
//                        for (int take_r=0;take_r<2;take_r++){
//                            process_kek();
//                            int sum_takes=take_l+take_r;
//                            for (int i=0;i<=n;i++){
//                                if (i>=sum_takes){
//                                    inc(dp[q2][i-sum_takes],to_add[i]);
//                                }
//                            }
//                        }
//                    }
                }
            }

            swap(q1,q2);
        }
        return dp[q1][0];
    }
//}

const bool final_version = 1;
const bool calc_time = 0;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    // if (calc_time){
    //     cout<<solve2::solve(8000,200)<<"\n";
    //     return 0;
    // }

    int n,m;
    cin>>n>>m;
    if (final_version){
        cout<<solve(n,m)<<"\n";
        return 0;
    }
//    cout<<solve1::solve(5,5)<<"\n";
//    cout<<solve2::solve(5,5)<<"\n";
//    cout<<solve1::solve(n,m)<<"\n";
//    cout<<solve2::solve(n,m)<<"\n";
//    cout<<solve1::solve(18,13)<<"\n";
//    cout<<solve2::solve(18,13)<<"\n";
//    cout<<solve1::solve(100,100)<<"\n";
//    cout<<solve2::solve(100,100)<<"\n";
}
