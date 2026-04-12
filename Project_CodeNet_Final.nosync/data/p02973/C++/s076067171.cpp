#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<math.h>
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

    for(int i = 1; i < n; i++){
        if(a[i] <= col[0]) col.push_front(a[i]);
        else{
            int j = 0;
            while(j < col.size()){
                if(a[i] <= col[j]) break;
                j++;
            }
            j--;
            col[j] = a[i];
        }
    }

    cout << col.size() << endl;

    return 0;
}