#include <bits/stdc++.h>
using namespace std;

int m=1000000007;

long long p(long long a) {
    int aa=a;
    queue<int> q;
    while (aa!=0) {
        if (aa%2==1) q.push(1);
        else q.push(0);
        aa/=2;
        //cout << aa << endl;
    }
    long long count=1;
    long long b=2;
    while(!q.empty()) {
        if (q.front()==1) {
            count*=b;
            count%=m;
            //cout << count << endl;
        }
        b*=b;
        b%=m;
        q.pop();
    }
    return count;
};
int main() {
   int N;
   cin >> N;
   long long A[N];
   for (int i=0; i<N; i++) cin >> A[i];
   long long total=0;
   for (int i=0; i<N; i++) {
       total+=A[i];
       total%=m;
   }
   total*=total;
   //cout << total << endl;
   total%=m;
   for (int i=0; i<N; i++) {
       total-=(A[i]*A[i]);
       //cout << total << endl;
       //cout << A[i] << endl;
       total%=m;
   }
   if (total<0) total+=m;
   //cout << total << endl;
   total*=p(m-2);
   total%=m;
   cout << total << endl;
}