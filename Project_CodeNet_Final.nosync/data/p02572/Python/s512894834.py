import itertools
n=int(input())
a=list(map(int,input().split()))
b=list(itertools.accumulate(a))
ans=0
for i in range(n-1):
  ans+=a[-i-1]*b[-i-2]
  ans%=10**9+7
print(ans)