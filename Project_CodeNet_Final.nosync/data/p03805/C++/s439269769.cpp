#include <bits/stdc++.h>
using namespace std;
/*
int count(int n, int m, int a[], int b[], int f){
    if (f == 1){
        return 0;
    }
    for (int i=0; i<m; i++){
        if (a[i] == n){
            count(b[i],m,a[i],b[i]);
        }else if (b[i] == n){
            count(a[i],m,a[i],b[i]);
        }
    }

}*/

int main(){
    int n,m;
    cin >> n >> m;
    int a[m],b[m];
    for (int i=0;i<m;i++){
        cin >> a[i] >> b[i];
    }
    int array[n-1];
    for (int i=0; i<n-1; i++){
        array[i] = i+2;
    }
    int root[n];
    root[0] = 1;
    int count = 0;
    do{
        for(int i=0; i<n-1; i++){
            root[i+1] = array[i];
        }
        for (int i=0; i<n-1; i++){
            int f = 0;
            for (int j=0; j<m; j++){
                /*cout << root[i];
                cout << a[j];
                cout << root[i+1];
                cout << b[j] << endl;*/
                if (root[i] == a[j]){
                    if (root[i+1] == b[j]){
                        f = 1;
                    }
                }else if (root[i] == b[j]){
                    if (root[i+1] == a[j]){
                        f = 1;
                    }
                }
                //cout << f << endl;
            }
            if (f == 0){
                break;
            }
            if (f == 1 && i == n-2){
                count++;
            }
        }
    }while(next_permutation(array,array+n-1));
    cout << count << endl;
    return 0;
}