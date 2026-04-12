#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<string>
#include<numeric>
#include<set>
#include<deque>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    deque<int> col;
    col.push_front(a[0]);
    int left, right, mid;

    for(int i = 1; i < n; i++){
        if(a[i] <= col[0]) col.push_front(a[i]);
        else{
            left = -1;
            right = col.size();
            while(right - left > 1){
                mid = left + (right - left) / 2;
                if(a[i] > col[mid]) left = mid;
                else right = mid;
            }
          	col[left] = a[i];
        }
    }

    cout << col.size() << endl;

    return 0;
}