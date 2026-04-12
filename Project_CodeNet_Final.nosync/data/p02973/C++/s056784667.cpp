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
            left = 0;
            right = col.size() - 1;
            while(left < right){
                mid = (left + right) / 2;
                if(a[i] <= col[mid]) right = mid;
                else left = mid + 1;
            }
          	if(col[left] >= a[i]) col[left-1] = a[i];
            else col[left] = a[i];
        }
    }

    cout << col.size() << endl;

    return 0;
}