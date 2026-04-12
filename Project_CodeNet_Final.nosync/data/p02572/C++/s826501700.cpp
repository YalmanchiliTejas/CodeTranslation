#include<iostream>
using namespace std;
#include<cmath>
long long int m = pow(10,9) + 7;
int main()
{
    long long int n ;
    cin >> n;
    long long int flag = 0;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        flag+=arr[i];
    }
    long long int final_arr[n];
    for(int i=0;i<n;i++){
        final_arr[i] = flag - arr[i];
        flag-=arr[i];
    }
    long long int product = 0;
    for(int i=0;i<n;i++){
        product += (((arr[i] % m) * (final_arr[i] % m))%m);
        product = product % m;
    }
    cout << product << endl;
}
