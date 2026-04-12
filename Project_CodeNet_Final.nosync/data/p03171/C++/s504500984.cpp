#include <iostream>
#include <vector>

using namespace std ;

void print2dvector(vector<vector<long long int> > v){
    for (int  i=0 ; i<v.size() ; i++){
        for(int j=0 ; j<v[0].size() ; j++)
            cout << v[i][j] << " " ;
        cout << "\n" ;
    }
}

int main(){
    int n ;
    cin >> n ;
    
    vector<int> a(n, 0) ;
    
    for (int i=0 ; i<n ; i++)
        cin >> a[i] ;
    
    vector<vector<long long int> > dp (n, vector<long long int> (n, 0)) ;
    
    for (int i=n-1 ; i>=0 ; i--){
        for (int j=i ; j<n ; j++){
            if (i == j)
                dp[i][j] = a[i] ;
            else
                dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]) ;
        }
    }
    
//    print2dvector(dp) ;
    
    cout <<  dp[0][n-1] << "\n" ;
    
    return 0 ;
}
