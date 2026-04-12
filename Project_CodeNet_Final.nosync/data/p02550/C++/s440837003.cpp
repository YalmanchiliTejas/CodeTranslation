#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
#include<vector>

typedef unsigned long long ULL;
typedef long long LL;

using namespace std;

void process();
int main(){
    process();
    return 0;
}

void process(){
    ULL N,X,M;
    ULL data;
    ULL *sum;
    ULL count;
    LL *use;
    ULL f;
    ULL i;
    ULL loop_start,loop_end;
    ULL mod,loops;
    ULL mod_sum,loop_sum;
    cin >> N >> X >> M;
    sum = new ULL[M+1];
    use = new LL[M];
    for(i=0;i<M;i++){
        use[i] = -1;
    }
    data = X;
    sum[0] = 0;
    sum[1] = X;
    use[X] = 1;
    loop_start = 1;
    loop_end = N;
    for(i=1;i<= M && i < N;i++){
        data = (data * data) % M;
        sum[i+1] = sum[i] + data;
        if( use[data] != -1){
            loop_start = use[data];
            loop_end = i;
            break;
        }
        use[data] = i+1;
        
    }
    //cout << sum[6] << endl;
    f = loop_end - loop_start + 1;
    loops = (N - loop_start + 1) / f;
    mod = (N - loop_start + 1) % f;
    loop_sum = sum[loop_end] - sum[loop_start-1];
    mod_sum = sum[loop_start + mod-1] - sum[loop_start-1];
    cout << sum[loop_start-1] + loop_sum * loops  + mod_sum << endl;
/*    cout << "check" << endl;
    cout << loop_start << ":" << loop_end << endl;
    cout << f << endl;
    cout << loops << endl;
    cout << mod << endl;
    cout << sum[loop_start] << ":" << sum[loop_start-1] << endl;
    cout << sum[loop_end] - sum[loop_start] << endl;
    cout << N << ":" << loop_start-1 + f * loops + mod << endl; */
    return;
}
