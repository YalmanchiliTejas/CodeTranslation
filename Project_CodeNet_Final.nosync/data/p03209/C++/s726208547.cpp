#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)

vector<long long>pati,nagasa;

tuple<long long, long long> eat(long long n, long long x){
    if (n == 0){
        if (x == 0) return forward_as_tuple(0,1);
            else return forward_as_tuple(1,1);
    }
    long long eaten = 0,l = 1,a,b;
    if (nagasa[n-1] > 0){
        if ((x>nagasa[n-1]+l) || (x == -1)){
            eaten += pati[n-1];
            l += nagasa[n-1];
        }else if (x > l){
            tie(a,b) = eat(n-1,x-l);
            eaten += a;
            l += b;
        }
    }else if ((x > 1) || (x == -1)){
        tie(a,b) = eat(n-1,x-l);
        eaten += a;
        l += b;
    }
    if (nagasa[n] == 0){
        if (nagasa[n-1] > 0){
            pati[n] = pati[n-1]*2+1;
        }else{
            tie(a,b) = eat(n-1,-1);
            pati[n-1] = a; nagasa[n-1] = b;
            pati[n] = a*2 +1;
        }
        nagasa[n] = l*2+1;
    }
    if ((x > l) || (x == -1)){
        eaten += 1; l += 1;
    }
    if ((x>nagasa[n-1]+l) || (x == -1)){
        eaten += pati[n-1];
        l += nagasa[n-1];
    }else if (x > l){
        tie(a,b) = eat(n-1,x-l);
        eaten += a;
        l += b;
    }
    if ((x > l) || (x == -1)) l += 1;
    return forward_as_tuple(eaten,l);
}

int main()
{
    long long n,x,a,b;
    cin >> n >> x;
    rep(i,n){
        pati.push_back(0); nagasa.push_back(0);
    }
    pati[0] = 1; nagasa[0] = 1;
    tie(a,b) = eat(n,x);
    cout << a << endl;
    return 0;
}