//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)
typedef long long ll;

int n;
vector<int> H(21);

bool judge(int index){
    if (index == 0) return true;
    
    FOR(i,0,index){
        if (H[i] > H[index]) return false;
    }
    return true;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
    cin >> n;
    
    FOR(i,0,n){
        cin >> H[i];
    }
    
    //cout << "H:" << endl;
    //FOR(i,0,n) cout << H[i] << endl;
    
    //0~iまででHiがmaxなら海見える
    int count = 0;
    FOR(i,0,n){
        //cout << judge(i) << endl;
        if (judge(i)) count++;
    }
    
    cout << count << endl;
}