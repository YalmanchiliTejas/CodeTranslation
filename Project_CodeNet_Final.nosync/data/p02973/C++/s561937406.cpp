#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

vector<int> vec(0);

int bin_search(int left, int right, int x){
    int mid=(left+right)/2 + (left+right)%2;
    mid=max(mid,0);
    if (mid==right){
        vec[mid]=x;
        return mid;
    }

    if (vec[mid] > x){
        return bin_search(left, mid, x);
    }else{
        return bin_search(mid, right, x);
    }
}

void cout_vec(vector<int> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    int N;
    cin >> N;
    vector<long long> A(N,0);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    vec.push_back(A[N-1]);

    for(int i=N-2; i>=0; i--){
        int size = vec.size();
        if(vec[size-1]<=A[i]){
            vec.push_back(A[i]);
            //cout << A[i] << endl;
            continue;
        }
        bin_search(-1,size-1,A[i]);
    }
    //cout_vec(vec);
    int ans = vec.size();
    cout << ans << endl;
}