#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
#include <set>
#include <map>
#define INF 1000000000
#define rep(i,n) for(int i =0;i<n;i++)
using namespace std;
typedef long long int ll;


int main(){
    for(;;){
        string A;
        cin >> A;
        if(A=="#")break;
        map<char,int> t;
        t['a']=1;
        t['b']=1;
        t['c']=1;
        t['d']=1;
        t['e']=1;
        t['f']=1;
        t['g']=1;
        t['h']=2;
        t['i']=2;
        t['j']=2;
        t['k']=2;
        t['l']=2;
        t['m']=2;
        t['n']=2;
        t['o']=2;
        t['p']=2;
        t['q']=1;
        t['r']=1;
        t['s']=1;
        t['t']=1;
        t['u']=2;
        t['v']=1;
        t['w']=1;
        t['x']=1;
        t['y']=2;
        t['z']=1;
        int ch = 0;
        int times=0;
        for (int i=0; i<A.length(); i++) {
            int ho = t[A[i]];
            if(ch == 0){
                ch = ho;
                continue;
            }
            if (ch == ho) {
                continue;
            }else{
                times++;
                ch = ho;
            }
        }
        cout << times << endl;
    }
}