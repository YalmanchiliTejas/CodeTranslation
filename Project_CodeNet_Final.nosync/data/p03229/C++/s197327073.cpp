//g++ -std=c++11 -Wall -O2 -o main.exe main.cpp
//g++ -std=c++14 -Wall -O2 -o main.exe main.cpp
 
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <queue>
#include <stack>
#include <tuple>
 
using namespace std;
 
#define ll long long int
#define sortasc(v, T) sort(v.begin(), v.end(), less<T>())
#define sortdesc(v, T) sort(v.begin(), v.end(), greater<T>())
 
//------
 
int N;
vector<int> A;
 
int main(){
    cin >> N;
 
    int t;
    for(int i = 0; i < N; i++){
        cin >> t;
        A.push_back(t);
    }
 
    sortasc(A, int);
 
    vector<int> less, more;
    for(int i = 0; i < N; i++){
        if(i < (N + 1) / 2){
            less.push_back(A[i]);
        }
        else{
            more.insert(more.begin(), A[i]);
        }
    }

    less.insert(less.begin(), less[less.size() - 1]);
 
    ll sum1 = 0;
    for(int i = 0; i < (N - 1); i++){
        sum1 += more[i / 2] - less[(i + 1) / 2];
    }
 
    sortdesc(A, int);
  
    less.clear(); more.clear();
    for(int i = 0; i < N; i++){
        if(i < (N + 1) / 2){
            less.push_back(A[i]);
        }
        else{
            more.insert(more.begin(), A[i]);
        }
    }
 
    less.insert(less.begin(), less[less.size() - 1]);
 
    ll sum2 = 0;
    for(int i = 0; i < (N - 1); i++){
        sum2 += less[(i + 1) / 2] - more[i / 2];
    }

//    cout << sum1 << ' ' << sum2 << endl;
    cout << max(sum1, sum2) << endl;
    return 0;
}