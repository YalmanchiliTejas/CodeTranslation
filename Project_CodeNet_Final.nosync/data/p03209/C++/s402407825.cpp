#include<cstdio>
using ull = unsigned long long;

ull solve(unsigned level, ull layer){
	if(!level) return layer;
	if(layer == 1) return 0ull;
	if(layer == (1ull << level + 2) - 3) return (1ull << level + 1) - 1;
	if(layer <= (1ull << level + 1) - 2) return solve(level - 1, layer - 1);
	if(layer >= 1ull << level + 1) return (1ull << level) + solve(level - 1, layer - (1ull << level + 1) + 1);
	return 1ull << level;
}

int main(){
	unsigned N;
	ull X;
	scanf("%u %llu", &N, &X);
	printf("%llu\n", solve(N, X));
	return 0;
}