/*
   AtCoder Submission
*/

#include<bits/stdc++.h>

using namespace std;

/* typedefs */
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector <si> vsi;
typedef vector <ii> vii;
typedef vector <int> vi;
typedef vector <char> vc;
typedef vector <string> vs;
typedef map <string,vs> msvs;
typedef map <string,int> msi;
typedef map <string,string> mss;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    if(A + B < C * 2){
        cout << X * A + Y * B << endl;
    } else {
        int numAB = min(X, Y);
        int cost = numAB * C * 2;
        if(C * 2 > (X > Y ? A : B)){
            cost += (-1 * numAB + (X > Y ? X : Y)) * (X > Y ? A : B);
        } else {
            cost += (-1 * numAB + (X > Y ? X : Y)) * C * 2;
        }
        cout << cost << endl;
    }


    return 0;
}
