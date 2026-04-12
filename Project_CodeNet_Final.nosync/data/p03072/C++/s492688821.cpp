#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i=0;i<N;i++) cin>>H.at(i);
    int Hmax = 0;
    int n = 0;
    for (int i=0;i<N;i++) {
        if (H.at(i)>=Hmax){
            n++;
            Hmax = H.at(i);
        }
    }
    cout << n << endl;
    
    
    
    
    
    
//    int A,B;
//    cin >> A >> B;
//    int c;
//    if (A==B) c=2*A;
//    else if (A>B) c=2*A-1;
//    else c=2*B-1;
//    cout << c << endl;
    
    
    
//    vector<int> a(M);
//    vector<int> b(M);
//    vector<int> n(N);
    
//    for (int i=0;i<M;i++) cin>>a.at(i)>>b.at(i);
//    for (int i=0;i<N;i++) {
//        n.at(i) = 0;
//        for (int j=0;j<M;j++){
//            if (a.at(j)==i+1) n.at(i)++;
//            if (b.at(j)==i+1) n.at(i)++;
//        }
//        cout << n.at(i) << endl;
//    }
}
