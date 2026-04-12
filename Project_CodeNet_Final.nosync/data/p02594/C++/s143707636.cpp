//
//  header_useful.h
//  c++_acm
//
//  Created by 李弘辰 on 2019/7/23.
//  Copyright  2019 李弘辰. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <utility> // pair
#include <map>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <algorithm> // sort
#include <string>
#include <stack>
#include <queue>
#include <fstream>
#include <bitset>


using namespace std;

#define ll long long
#define lll __int128
#define uchar unsigned char
#define ushort unsigned short
#define uint unsigned int
#define ulong unsigned long
#define ull unsigned long long

#define INT_INF 0x7fffffff

#define pi acos(-1)

#define mx(a,b) (a) > (b) ? (a) : (b)
#define mn(a,b) (a) < (b) ? (a) : (b)
#define mem(a,b) memset(a,b,sizeof(a))
#define fre(a) freopen(a,"r",stdin)

#define cio ios::sync_with_stdio(false); // Do not use it with "scanf" and other c input!
#define pb push_back
#define rep(i,a,b) for (int i = a;i <= b;i ++)
#define pre(i,a,b) for (int i = a;i >= b;i --)
#define REP(i,a,b) for (int i = a;i < b;i ++)

#define read(a,s,n) rep(i,s,n) scanf("%d",a + i);
#define READ(a,s,n) REP(i,s,n) scanf("%d",a + i);

#define read_ll(a,s,n) rep(i,s,n) scanf("%lld",a + i);
#define READ_ll(a,s,n) REP(i,s,n) scanf("%lld",a + i);

#define _T_(T) int T;scanf("%d",&T);while (T --)
#define __T _T_(TTESTCASES)
#define _E_(T) while (~T)

#define Tprint(a,s,e) {int f=1;REP(i,s,e){if(f)f=0;else printf(" ");printf("%d",a[i]);}}


#define endl '\n'

#define itn int
#define iny int
#define nit int
#define inr int
#define mian main
#define iman main
#define mina main
#define mian main
#define ednl endl
#define fro for
#define fir for
#define reutrn return
#define retunr return
#define reutnr return


/* header_useful_h */


int main(){
    
    ll a;
    scanf("%lld",&a);
    if (a >= 30) puts("Yes");
    else puts("No");
    
    return 0;
}
