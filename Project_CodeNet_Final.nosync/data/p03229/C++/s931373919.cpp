#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n] = {};
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    
    long long head = 0;
    long long prev = 0;
    for(int i=0; i<n; i++){
        if(i%2 == 0){
            int j = i/2;
            if(i == n-1) 
                head += max(abs(a[j] - a[0]), abs(a[j]- prev));
            else
                if(i!=0) head += abs(a[j] - prev);
            prev = a[j];
        }else{
            int j = n-1-i/2;
            if(i == n-1)
                head += max(abs(a[j] - a[0]), abs(a[j] - prev));
            else 
                head += abs(a[j] - prev);
            prev = a[j];
        }
        //cout << prev << ": "  << head << endl;
    }
    
    long long tail = 0;
    prev = 0;
        for(int i=0; i<n; i++){
        if(i%2 != 0){
            int j = i/2;
            if(i == n-1) 
                tail += max(abs(a[j] - prev), a[n-1] - a[j]);
            else 
                tail += abs(a[j] - prev);
            prev = a[j];
        }else{
            int j = n-1-i/2;
            if(i == n-1)
                tail += max(abs(a[j] - prev), a[n-1] - a[j]);
            else 
                if(i!=0) tail += abs(a[j] - prev);
            prev = a[j];
        }
        //cout << prev << ": "  << tail << endl;
    }
    
    //cout << head << " " << tail << endl;
    cout << max(head, tail) << endl;
    return 0;
}
