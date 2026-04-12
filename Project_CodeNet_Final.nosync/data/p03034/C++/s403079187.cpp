#include <iostream>
#include <set>

using namespace std;

int main(){
    int N;
    cin >> N;
    long s[100000];
    long ans = 0;
    for(int i = 0; i < N; i++) cin >> s[i];
    for(int i = 1; i < (N/2); i++){
        long tmp = 0;
        long sum = 0;
        set<int> st;
        for(int j = 1; j*i < N; j++){
            sum += s[i*j];
            st.insert(i*j);
            sum += s[N-i*j-1];
            if(st.count(N-i*j-1) != 0) break;
            if(N-i*j-1 < i) break;
            ans = max(sum, ans);
        }
    }
    cout << ans << endl;
}