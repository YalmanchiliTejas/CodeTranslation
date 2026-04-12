#include <bits/stdc++.h>
using namespace std;
long long n,s1,s2,vals[200005],sufans[200005],prefans[200005];

int main(){
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0 ; i < n ; i += 1){
        cin >> vals[i];
        if(i % 2 == 0){
            s1 += vals[i];
        }else{
            s2 += vals[i];
        }
    }
    for(int i = n-1 ; i >= 0 ; i -= 1){
        if((n-i)%2 == 0){
            sufans[i] = vals[i] + max(sufans[i+2],sufans[i+3]);
        }else{
            sufans[i] = vals[i] + sufans[i+2];
        }
    }
    for(int i = 0 ; i < n ; i += 1){
        if((i+1)%2 == 0){
            long long a = -1000000000000000000;
            if(i-3 >= 0){
                a = prefans[i-3];
            }
            prefans[i] = vals[i]+max(prefans[i-2],a);
        }else{
            long long a = 0;
            if(i-2 >= 0){
                a = prefans[i-2];
            }
            prefans[i] = vals[i]+a;
        }
    }
    if(n % 2 == 0){
        cout << max(prefans[n-1],prefans[n-2]) << endl;
        return 0;
    }
    long long maxi = sufans[2];
    for(int i = 0 ; i+3 <= n ; i += 1){
        if((i+1)%2 == 0){
            maxi = max(maxi,sufans[i+3]+max(prefans[i],prefans[i-1]));
        }else{
            maxi = max(maxi,prefans[i]+max(sufans[i+3],sufans[i+4]));
        }
    }
    cout << max(maxi,prefans[n-2]) << endl;
}