import itertools
ans=0
n=int(input())
li=list(map(int,input().split()))
L=list(itertools.accumulate(li))
for i in range(1,n):
    ans+=L[i-1]*li[i]
print(ans%(10**9+7))