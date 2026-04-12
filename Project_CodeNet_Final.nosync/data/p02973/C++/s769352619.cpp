#include <bits/stdc++.h>

std::vector< int > last;

int binary_search(int key) {
    int left = -1;
    int right = (int)last.size();
    
    while(right - left > 1){
        int mid = left + (right - left) / 2;
        
        if(last[mid] < key){
            right = mid;
        }else{
            left = mid;
        }
    }
    
    return right;
}

int main(){
    int N;
    std::cin >> N;
    std::vector< int > A(N);
    for(int i=0; i<N; i++){
        std::cin >> A[i];
    }
    
    last.resize(1);
    last[0] = A[0];
    
    for(int i=1; i<N; i++){
        int index = binary_search(A[i]);
        //std::cout << "index" << index << std::endl;
        if(index == last.size()){
            last.push_back(A[i]);
        }else{
            last[index] = A[i];
        }
        //std::cout << "vector ";
        //for(int a=0; a<last.size(); a++){
        //    std::cout << last[a] << " ";
        //}
        //std::cout << std::endl;
    }
    
    std::cout << last.size() << std::endl;
    
    return 0;
}

