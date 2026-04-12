#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long int N, X;
    cin >> N >> X;
    
    long long int max_length=1;
    int n=0;
    vector<long long int> max_p_num(N+1, 0);
    max_p_num[0] = 1;
    while(n<N) {
        max_length *= 2;
        max_length += 3;
        
        max_p_num[n+1] = max_p_num[n]*2+1;
        // cout << max_p_num[n+1] << endl;
        n++;
    }
    // cout << max_length << endl;
    
    long long int s=1, e=max_length;
    long long int cur=(s+e)/2;
    long long int ans=0;
    long long int curN=N-1;
    if(cur==X) {
        ans = max_p_num[curN]+1;
    }
    while(cur!=X) {
        // cout << cur << endl;
        if(cur<X) {
            if(curN>=0) {
                ans += max_p_num[curN]+1;
            } else {
                ans += 1;
                break;
            }
            
            s = cur+1;
            if(e!=X) {
                e--;
            } else {
                ans += max_p_num[curN];
                break;
            }
            cur = (s+e)/2;

            if(cur==X) {
                if(curN>0) {
                    ans += max_p_num[curN-1]+1;
                } else if(curN==0) {
                    ans += 1;
                }
            }
        } else if(cur>X) {
            e = cur-1;
            if(s!=X) {
                s++;
            } else {
                break;
            }
            cur = (s+e)/2;
            
            if(cur==X) {
                if(curN>0) {
                    ans += max_p_num[curN-1]+1;
                } else if(curN==0) {
                    ans += 1;
                }
            }
        }
        
        curN--;
    }
    
    cout << ans << endl;


    return 0;
    
}
