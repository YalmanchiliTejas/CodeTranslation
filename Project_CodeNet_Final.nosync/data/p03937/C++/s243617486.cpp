#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <random>
#include <chrono>
#include <bitset>
#include <fstream>
#include <sstream>

using namespace std;

typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,k;

char M[10][10];

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll a,b,c,d,e;
    ll c1,c2,c3,c4;

   cin >> n >> m;
   bool pos = 1;
   for(c1 = 0; c1 < n; c1++){
        for(c2 = 0; c2 < m; c2++){
            char ch;
            cin >> ch;
            M[c1][c2] = ch;
        }
   }

   for(c3 = 0; c3 < n+m-1; c3++){
    
    ll coun = 0;
    for(c1 = 0; c1 < n; c1++){
        for(c2 = 0; c2 < m; c2++){
            if(c1+c2 == c3){
                if(M[c1][c2] == '#')coun++;
            }
        }
    }
    if(coun != 1)pos = 0;
    
   }

    if(pos){
        cout << "Possible\n";
    }
    else{
        cout << "Impossible\n";
    }

    return 0;
}
