#include<bits/stdc++.h>
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define M 1000000007
using namespace std;
long long int findProductSum(vector<long long int> A, int n)
{
    long long int array_sum = 0;
    for (int i = 0; i < n; i++)
        array_sum = array_sum + A[i];

    long long int array_sum_square = 1;
    array_sum_square = (array_sum_square*array_sum)%M;
    array_sum_square = (array_sum_square*array_sum)%M;

    long long int individual_square_sum = 0;
    for (int i = 0; i < n; i++) {
        long long int prod = 1;
        prod = (prod*A[i])%M;
        prod = (prod*A[i])%M;
        individual_square_sum = (individual_square_sum + prod) % M;
    }

    return (((array_sum_square - individual_square_sum)%M+M)%M)/2;
}
int main() {

    jaldi

    long long int n;
    cin>>n;
    vector<long long int> a(n);
    for(long long int i=0;i<n;i++) {
        cin>>a[i];
    }

//long long int ans = findProductSum(a,n);
//    ans = ans%M;
//    cout<<ans<<'\n';
    vector<long long int> suffix(n-1,0);
    suffix[n-2]=a[n-1];
    for(long long int i=n-3;i>=0;i--) {
        suffix[i] = (suffix[i+1]+a[i+1]);
    }

    long long int ans = 0;
    for(long long int i=0;i<n-1;i++) {
        long long int product = 1LL;
        product = ((a[i]%M)*(suffix[i]%M) )% M;
        ans = (ans+product)%M;
    }
    cout<<ans<<'\n';
}