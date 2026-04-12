#include <iostream>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    long long int pre[n]={0};
    pre[n-1]=(arr[n-1]%1000000007);
    for(long long int i=n-2; i>=0; i--){
        pre[i]=((arr[i]%1000000007)+(pre[i+1]%1000000007))%1000000007;
    }
    long long int sum=0;
    for(long long int i=0; i<n-1; i++){
        sum=(sum + ((arr[i]%1000000007)*(pre[i+1]%1000000007))%1000000007)%1000000007;
    }
    cout << sum;
    return 0;
}