#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;

#define fi first
#define se second
typedef long long LL;
typedef long double LD;

int N,a[200010],arr[500010];

int main(){
    cin >> N;

    int i;
    for (i=1; i<=N; i++)
        cin >> a[i];

    int l=200010,r=l,e=r;
    arr[l]=a[1];
    for (i=2; i<=N; i++){
        if (e==l) arr[--l]=a[i],e=r;
        else arr[++r]=a[i],e=l;
    }

    if (e==r){
        for (i=l; i<=r; i++)
            cout << arr[i] << " ";
    }
    else {
        for (i=r; i>=l; i--)
            cout << arr[i] << " ";
    }
    return 0;
}
