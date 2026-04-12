#include <iostream>
#include <math.h>
using namespace std;

int p_num[51];

//Level n のベーガーをlastまで食べる
long count_p(int n, long last){
    // DP
    long length = pow(2,n+2) - 3;
    if(last == length && p_num[n] != -1){
        return p_num[n];
    }
    
    //再起止め
    if(last<=1){
        return 0;
    }
    if(n==0){
        return 1;
    }
    
    
    //順当に数える
    long cnt = 0;
    
    if(last >= pow(2,n+1)-2){
        cnt += count_p(n-1, pow(2,n+1)-3);
    }else{
        cnt += count_p(n-1, last-1);
        return cnt;
    }
    //cout << cnt << "po";
    if(last >= pow(2,n+1)-1){
        cnt += 1;
    }
    
    if(last >= pow(2,n+2)-4){
        cnt += count_p(n-1, pow(2,n+1)-3);
        p_num[n] = cnt;
    }else{
        cnt += count_p(n-1, last - (pow(2,n+1) - 1));
        
    }
    
    return cnt;
}

int main(void){
    p_num[0]=1;
    for(int i=1;i<51;i++){
        p_num[i] = -1;
    }
    // Your code here!
    long N, X;
    cin >> N >> X;
    long ret = 0;
    ret = count_p(N, X);
    cout << ret << endl;
}
