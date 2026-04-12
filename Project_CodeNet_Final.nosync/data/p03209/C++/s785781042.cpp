#include<iostream>
using namespace std;

typedef unsigned long long ull;

ull len[51];
ull p_num_list[51];

ull calc_len(int n){
    if(n==0){
        len[n] = 1;
        return 1;
    }
    else{
        ull l = calc_len(n-1)*2+3;
        len[n] = l;
        return l;
    }
}

ull calc_p_num(int n){
    if(n==0){
        p_num_list[n] = 1;
        return 1;
    }
    else{
        ull l = calc_p_num(n-1)*2+1;
        p_num_list[n] = l;
        return l;
    }
}


ull func(int n, ull x){
    if(n==1){
        if(x==1)
          return 0;
        else if(x <= 4)
          return x-1;
        else
          return 3;
    }

    if(x <= 1){
        return 0;
    }
    else{
        x--;
        ull res = 0;
        if(x <=len[n-1]){
            //cout << n << ", " << x << " : test1" << endl;
            return func(n-1, x);
        }
        else if(x == len[n-1]+1){
            //cout << n << ", " << x << " : test2" << endl;
            return p_num_list[n-1] + 1;
        }
        else{
            x = x - len[n-1]-1;
            //cout << n << ", " << x << " : test3" << endl;
            return func(n-1, min(x, len[n-1])) + 1 + p_num_list[n-1];
        }
    }
}


int main(){
    int N;
    ull X;
    cin >> N >> X;

    calc_len(50);
    for(int i=0;i<=50;i++){
        //cout << len[i] << endl;
    }

    calc_p_num(50);
    for(int i=0;i<=50;i++){
        //cout << p_num_list[i] << endl;
    }

    ull ans = func(N, X);
    cout << ans << endl;
    return 0;
}
