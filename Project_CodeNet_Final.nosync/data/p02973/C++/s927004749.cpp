#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void){
    // Your code here!
    long long n;
    vector<long long> x;
    
    cin >> n;
    for(long long i = 0; i < n; i++){
        long long temp;
        cin >> temp;
        x.push_back(temp);
    }
    
    vector<long long> color;
    for(long long i = n - 1; 0 <= i; i--){
        vector<long long>::iterator itr = upper_bound(color.begin(), color.end(), x[i]);

        if(distance(color.begin(), itr) >= color.size())
            color.push_back(x[i]);
        else
            color[distance(color.begin(), itr)] = x[i];
    }
    
    cout << color.size() << endl;
    
    return 0;
    
}