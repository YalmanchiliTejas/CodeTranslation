#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N;
    int sum = 1;
    int max;
    cin >> N;
    std::vector<int> v(N);

for(int i = 0; i < N; ++i)
    cin >> v[i];

max = v[0];

for(int i = 1; i < N; ++i){
    if(v[i] >= max){
    sum += 1;
    max = v[i];
    }
}

std::cout << sum << endl;

 return 0;    
}