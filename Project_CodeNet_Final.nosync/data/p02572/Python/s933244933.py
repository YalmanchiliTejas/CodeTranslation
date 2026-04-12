n=input()
arr=map(int, raw_input().split())
sums=[0]*n
sums[0]=arr[0]
for i in xrange(1, n):
  sums[i]=sums[i-1]+arr[i];
mod=10**9+7
ans=0
for i in xrange(n):
  ans=(ans%mod+arr[i]*(sums[-1]-sums[i])%mod)%mod
print ans
