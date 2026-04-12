//538B
#include<bits/stdc++.h>

using namespace std;



int main(){

    cout << fixed;
    cout << setprecision(0);

    int a ,b , c;
    cin >> a >> b>>c;

    int n = a*100 + 10*b + c ;

    if(n%4==0)
        cout << "YES" ;
    else
        cout << "NO" ;

	return 0;
}

