#include <iostream>
using namespace std;

long long x;
long long i = 0;
long long num_pathi[51] = {};

long long dfs(long long n, long long j)
{
    long long count = 0;
    
    if(n == 1){
        i++;
        return 1;
    }
    if(i >= x)
        return 0;
    
    i++;
    if(i >= x)
        return count;
    
    if(i + (n - 3) / 2 < x){
        count += num_pathi[j-1];
        i += (n - 3) / 2;
    }
    else{
        count += dfs((n - 3) / 2, j-1);
        i++;
    }
    
    if(i >= x)
        return count;

    i++;
    count++;
    if(i >= x)
        return count;

    if(i + (n - 3) / 2 < x){
        count += num_pathi[j-1];
        i += (n - 3) / 2;
    }
    else{
        count += dfs((n - 3) / 2, j-1);
        i++;
    }
    
    return count;
}

int main(void){
    // Your code here!
    long long n, num = 1;
    
    cin >> n >> x;
    
    num_pathi[0] = 1;
    for(long long i = 0; i < n; i++){
        num = num * 2 + 3;
        num_pathi[i+1] = num_pathi[i] * 2 + 1;
    }

    cout << dfs(num, n) << endl;
    
    return 0;
}
