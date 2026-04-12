//
//  main.cpp
//  ABC124
//
//  Created by hiroaki on 2019/05/07.
//  Copyright © 2019年 hiroaki. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <set>
#include <cmath>
#include <algorithm>
#include <locale>

#define int long long
#define pb(n) push_back(n)
#define For(n,i) for(int (i)=0;(i)<(n);(i)++)
//#define ForJ(n) for(int j=0;j<n;j++)
//#define ForK(n) for(int k=0;k<n;k++)
#define Pr(n) cout<<n<<endl;
#define INS(v,n) for(int i=0;i<n;i++){cin >>v.at(i);}//vector 代入
#define ELM 100001 //問題によっては1000000001に変更
using namespace std;

int Product_set_min(int la,int ra,int lb,int rb){//A<B
    int r=0;;
    if (la<ra&&ra<lb&&lb<rb) {
        r= 0;
    }else if(la<=lb&&lb<=ra&&ra<=rb){
        r= lb;
    }else if(lb<=la&&la<=ra&&ra<=rb){
        r= la;
    }else if(lb<=la&&la<=rb&&rb<=ra){
        r= la;
    }else if(lb<rb&&rb<la&&la<ra){
        r= 0;
    }
    return r;
}
int Product_set_max(int la,int ra,int lb,int rb){//A<B
    int r=0;;
    if (la<ra&&ra<lb&&lb<rb) {
        r= 0;
    }else if(la<=lb&&lb<=ra&&ra<=rb){
        r= ra;
    }else if(lb<=la&&la<=ra&&ra<=rb){
        r= ra;
    }else if(lb<=la&&la<=rb&&rb<=ra){
        r= rb;
    }else if(lb<rb&&rb<la&&la<ra){
        r= 0;
    }
    return r;
}
string min (string m){
    transform(m.begin(), m.end(), m.begin(),towlower);
    return m;
}
signed  main(){
    int x,y,z;
    cin >> x>>y>>z;
    if (x%(y+z)<z) {
        cout<<x/(y+z)-1<<endl;
    }else{
        cout<<x/(y+z)<<endl;
    }
    return 0;
}

