#include<bits/stdc++.h>
using namespace std;

void solveeven(int n , int *arr)
{
    int ans[n];
    int left = n-1 ;
    for(int i = 0 ; i < (n/2) ; ++i){
        ans[i] = arr[left];
        left = left-2;
        if(left < 0) break;
    }
    int right = 0 ;
    for(int i = n/2 ; i<=n-1; ++i){
        ans[i] = arr[right] ;
        right = right + 2 ;
        if(right > n-2) break;
    }
    for(int i = 0 ; i <= n - 1 ; ++i){
        cout << ans[i] << " " ;
    }
    cout << endl ;
    return ;
}

void solveodd(int n , int *arr)
{
    int ans[n];
    int left = n-1 ;
    for(int i = 0 ; i < (n/2) + 1  ; ++i){
        ans[i] = arr[left];
        left = left-2;
        if(left < 0) break;
    }
    int right = 1 ;
    for(int i = (n/2) + 1 ; i<=n-1; ++i){
        ans[i] = arr[right] ;
        right = right + 2 ;
        if(right > n-2) break;
    }
    for(int i = 0 ; i <= n - 1 ; ++i){
        cout << ans[i] << " " ;
    }
    cout << endl ;
    return ;
}
void solve(int n , int *arr)
{
    if(n%2 == 0){
        solveeven(n , arr) ;
    }
    else solveodd(n , arr) ;
    return ;
}
int main()
{
    int n ;
    cin >> n ;
    int arr[n] ;
    for(int i = 0 ; i < n ; ++i){
        cin >> arr[i] ;
    }
    solve(n , arr) ;
}
