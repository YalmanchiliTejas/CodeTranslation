#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int N; 
	long long int X; 
	cin >> N >> X;
	long long int A[60] = {}; 
	A[0] = 1; 
	for(int i = 0; i < 55; i++){
		A[i+1] = 2 * A[i] + 3;  
	}
	long long int B[60] = {}; 
	B[0] = 1; 
	for(int i = 0; i < 55; i++){
		B[i+1] = 2 * B[i] + 1;  
	}
	long long int ans = 0; 
	for(int j = N; j >= 2; j--){
        if(X == 1){
                X = 0; 
                break; 
        }
	else if(X <= A[j-1] + 1){
		X--; 
	}
	else if(X == A[j-1] + 2){
		X = 0; 
		ans += B[j-1] + 1; break; 
	}
	else if(X < A[j]){
		ans += B[j-1] + 1; 
		X -= (A[j-1] + 2); 
	}
        else if(X == A[j]){
		ans += B[j]; 
		X = 0; 
                break;
	}
	}
	if(X == 2){ans += 1;}
	else if(X == 3){ans += 2;}
	else if(X >= 4){ans += 3;}
	cout << ans << endl; 
}