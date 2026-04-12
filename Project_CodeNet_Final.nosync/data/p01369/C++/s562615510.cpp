// Author :
// Date :
// Problem:
// Solution:
// Comment:

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstring>

#define pp push
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

using namespace std;

map <char,int> mpp;

void play(string str){
    int start = 0;
    
    for(int i = 1 ; i < str.size() ; i++){
        if(mpp[str[i]] != mpp[str[i-1]]) start++;
    }
    
    cout << start << endl;
}
main(){
    mpp['q']=1;
    mpp['w']=1;
    mpp['e']=1;
    mpp['r']=1;
    mpp['t']=1;
    mpp['a']=1;
    mpp['s']=1;
    mpp['d']=1;
    mpp['f']=1;
    mpp['g']=1;
    mpp['z']=1;
    mpp['x']=1;
    mpp['c']=1;
    mpp['v']=1;
    mpp['b']=1;
    mpp['y']=2;
    mpp['u']=2;
    mpp['i']=2;
    mpp['o']=2;
    mpp['p']=2;
    mpp['h']=2;
    mpp['j']=2;
    mpp['k']=2;
    mpp['l']=2;
    mpp['n']=2;
    mpp['m']=2;
    
    string str;
    
    while(cin >> str){
        if(str == "#") break;
        play(str);
    }
    
    #ifdef GEREL
        for(;;);
    #endif

    return 0;
}