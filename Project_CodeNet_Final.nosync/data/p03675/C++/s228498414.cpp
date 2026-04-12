#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<numeric>
#include<iomanip>
#include<utility>
#include<cstdlib>
#include<typeinfo>


using namespace std;
#define INF 1000000005
int main()
{
int n;
std::vector<int> a;
std::cin >> n;
for(int i = 0; i < n; i++){
    int temp;
    std::cin >> temp;
    a.push_back(temp);
}
std::vector<int> b(n, 0);
int bin = n % 2;
int indexa = 0;
int indexb = 1;
for(int i = 1; i <= n; i++){
   if(i % 2 == 1){
        b[indexa] = a[n - i];
        indexa++;
    } else {
        b[n - indexb] = a[n - i];
        indexb++;
    }
}
for(int i = 0; i < n - 1; i++){
    std::cout << b[i] << " ";
}
std::cout << b[n - 1] << std::endl;
return 0;
}