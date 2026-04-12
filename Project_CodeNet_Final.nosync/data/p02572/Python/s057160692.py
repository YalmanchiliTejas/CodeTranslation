from itertools import combinations
N=int(input())
A=list(map(int,input().split()))

zen=sum(A)


ans=0
part=0
for i in range(N-1):
    part+=A[i]
    ans+=A[i]*(zen-part)

print(ans%(10**9+7))    