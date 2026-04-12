#include <bits/stdc++.h>
using namespace std;

long    Pat(long N, long X, vector<long> &T, vector<long> &P) {
        if (N==0) return 0;
        long H=(T.at(N)-1)/2;
        if (T.at(N)-X<2) return P.at(N);
        else if (X-H>1) return (Pat(N-1, X-(T.at(N)+1)/2, T, P)+1+P.at(N-1));
        else if (X-H==1) return (1+P.at(N-1));
        else if (X-H==0) return P.at(N-1);
        else return Pat(N-1, X-1, T, P);
}

int     main() {
        long N, X;
        cin >>N >>X;
        vector<long> T(51);
        vector<long> P(51);
        T.at(0)=P.at(0)=1;
        for (long i=1; i<51; i++) {
                T.at(i)=T.at(i-1)*2+3;
                P.at(i)=P.at(i-1)*2+1;
        }
        cout << Pat(N, X, T, P) << endl;
        return 0;
}