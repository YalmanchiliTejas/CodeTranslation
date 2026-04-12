#include<bits/stdc++.h>
using namespace std;
int main(){
    int A, B, C, D, N, ans=0;
    vector<int> V(3);
    char tmp;
    string S;
    cin >> V[0] >>V[1] >>V[2];
    tmp = V[0]*100+V[1]*10+V[2]*1;
    if(tmp%4==0)
	puts("YES");
    else
	puts("NO");
    
    // cout <<ans<<endl;
    

    // string S;
    // cin >>S;
    // cout << S + "pp"<<endl;
    // if(A+B==C || B+C==A || C+A==B)
    // 	puts("Yes");
    // else
    // 	puts("No");
}
