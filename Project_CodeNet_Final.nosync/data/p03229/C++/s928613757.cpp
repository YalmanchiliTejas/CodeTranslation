#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <fstream>
#include <cstdlib>
typedef long long ll;

#define REP(i, N) for (int i = 0; i < (N); i++)
#define REPP(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define VSORT(c) sort((c).begin(),(c).end())
#define SZ(x) ((int)(x).size())

using namespace std;


int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    vector<ll> A;
    vector<ll> smallA;
    vector<ll> largeA;
    ll temp;
    list<ll> lst1,lst2; 
    list<ll>::iterator itr; 

    cin >> N;
    for(ll i = 0; i < N; i++){
        cin >> temp;
        A.push_back(temp);
    }
    VSORT(A);
    REP(i,N) smallA.push_back(A[i]);
    reverse(ALL(A));
    REP(i,N) largeA.push_back(A[i]);
    lst1.push_back(smallA[0]);
    lst2.push_back(largeA[0]);
    ll sf=1,sl=N-1;
    ll max = 0;
    if(N%2 == 0){
        for(ll i = 1; i < N/2 ; ++i){
            if(i%2==1){
                lst1.push_front(smallA[sl]);
                --sl;
                lst1.push_back(smallA[sl]);
                --sl;
            }else{
                lst1.push_front(smallA[sf]);
                sf++;
                lst1.push_back(smallA[sf]);
                sf++;
            }
        }
        lst1.push_front(smallA[sf]);
    }else{
        for(int i = 1; i < N/2+1 ; ++i){
            if(i%2==1){
                lst1.push_front(smallA[sl]);
                lst2.push_front(largeA[sl]);
                --sl;
                lst1.push_back(smallA[sl]);
                lst2.push_back(largeA[sl]);
                --sl;
            }else{
                lst1.push_front(smallA[sf]);
                lst2.push_front(largeA[sf]);
                sf++;
                lst1.push_back(smallA[sf]);
                lst2.push_back(largeA[sf]);
                sf++;
            }
        }
    }
    ll count = 0,l=0;
    for(itr=lst1.begin(); itr != lst1.end();itr++){
        smallA[l] = *itr;
        l++;
    }
    l=0;
    for(itr=lst2.begin(); itr != lst2.end();itr++){
        largeA[l] = *itr;
        l++;
    }

    REP(i,smallA.size()-1){
        count += abs(smallA[i] - smallA[i+1]);
    }
    max = count;
    count = 0;
    REP(i,largeA.size()-1){
        count += abs(largeA[i]-largeA[i+1]);
    }
    if(max < count) max = count;
    cout << max << endl;
    

    return 0;
}