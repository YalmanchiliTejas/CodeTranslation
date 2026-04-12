#include <iostream>
 
int main()
{
int N=0;
 
std::cin >> N; 
 
int sum=0;
 
for(int i=1;i<N+1;i++)
{
sum+=800;
if(i % 15 == 0)
sum-=200;
}
 
std::cout << sum << std::endl;
 
return 0;
}