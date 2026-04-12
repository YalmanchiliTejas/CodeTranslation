//#include<iostream>
//#include<algorithm>
//#include<string>
//#include <cmath>
//#include <vector>
#include <bits/stdc++.h>

#define ll long long
#define REP(x,n) for(int x=0;x<n;x++)

// vector 操作  vector<int> data(10,5) 10が5個　data(10) 要素数10
// v.size(), v.empty(), v.insert(itr,値), v.erase(itr) (first,last),
// sort(itr), find(all(x),値),reverse(itr),accumulate(itr,0) 積算,
//v.swap
// stringも同じ itrがただの数字になる
// s.substr(n,m)n番目以降m文字取り出す　erase(n,m)も  s.find
#define vei vector<int> 
#define velli vector<long long int> 
#define pb(x) push_back(x) // 末尾にxを加える
#define pb2 pop_back() // 末尾削除
#define all(x) (x).begin(),(x).end() //イテレーター
#define be(x) (x).begin()

using namespace std;

int main (){

    int n,m;
    cin >> n >> m;
    if(n==m) {
        cout << "Yes" << endl;
    }
    else {
    cout << "No"<< endl;
    }

}