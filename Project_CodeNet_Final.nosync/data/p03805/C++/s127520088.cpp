#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){

    int n,m;

    cin >> n >> m;

    int a[m],b[m];
    
    for(int i=0;i<m;i++)cin >> a[i] >> b[i];

    int A[n+1][n+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            A[i][j] = 0;
        }
    }

    for(int i=0;i<m;i++){
            A[a[i]][b[i]]++;
            A[b[i]][a[i]]++;
    }

    int B[n];

    int s=0;

    for(int i=0;i<n;i++)B[i] =i+1;

    do {
        bool is_ok = true;
        for (int i = 0; i < n-1; i++) {
            if(A[B[i]][B[i+1]] == 0){
                is_ok = false ;
                break;
            }
        }
        if(is_ok)s++;
        /*if(is_ok){
            for(int i=0;i<n;i++)cout << B[i] << endl;
        }*/
    } while(next_permutation(B+1, B +n));

    cout << s << endl;

}