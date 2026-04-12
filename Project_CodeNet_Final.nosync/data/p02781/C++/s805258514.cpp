#include <bits/stdc++.h>

std::string N;
int K;

long long count(int index, bool max_f, long long K_cur){
    if(K_cur == K){
        return 1;
    }
    if(index == N.size()){
        return 0;
    }
    long long cnt = 0;
    if(max_f){
        if(N[index] == '0'){
            cnt += count(index + 1, true, K_cur);
        }else{
            cnt += count(index + 1, true, K_cur+1);
            cnt += (N[index] - '0' - 1) * count(index + 1, false, K_cur+1);
            cnt += count(index + 1, false, K_cur);
        }
    }else{
            cnt += 9 * count(index + 1, false, K_cur+1);
            cnt += count(index + 1, false, K_cur);
    }
    return cnt;
}

int main(){
    std::cin >> N >> K;
    
    std::cout << count(0, true, 0) << std::endl;
    
    
    return 0;
}

