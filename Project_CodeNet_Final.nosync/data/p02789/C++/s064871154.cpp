#include <bits/stdc++.h>
#define pb push_back
#define Int int64_t
using namespace std;
const Int M=(Int)(1e9+7);

inline Int mmul(Int a,Int b){if(a>=M)a=a%M;if(b>=M)b=b%M;if(a*b>=M)return(a*b)%M;return(a*b);}
inline Int madd(Int a, Int b){if(a>=M)a=a%M;if(b>=M)b=b%M;if(a+b>=M)return(a+b)%M;return(a+b);}



int main()
{
    int A,B;
    cin>>A>>B;
    cout<<(A==B ? "Yes\n":"No\n");
}