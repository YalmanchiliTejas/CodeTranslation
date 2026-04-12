#include<bits/stdc++.h>
#define ll long long
using namespace std;

int isPal(string s){
    int n = s.size();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-1-i]) return 0;
    }
    return 1;
}

// cout << "Case #"<< k << " "<<
int a[213456], arr[213456], i1;

void pre(int arr[], int n){
      i1 = 1e5+1;
     a[i1] = arr[1];
     for(int i = 2; i <= n; i++){
         if(i%2){
            a[i1+i/2] = arr[i];
         }
         else{
            a[i1-i/2] = arr[i];
         }
     }

}

int main() {
	   int n;
	   cin >> n;
	   for(int i = 1; i <= n; i++) cin >> arr[i];
	   pre(arr, n);
	   if(n%2){
	      for(int j = i1+n/2; j >= i1-n/2; j--){
              cout << a[j] << " ";
	      }
	   }
	   else{
          for(int j = i1-n/2; j < i1+n/2; j++){
            cout << a[j] << " ";
          }
	   }
         return 0;
}
