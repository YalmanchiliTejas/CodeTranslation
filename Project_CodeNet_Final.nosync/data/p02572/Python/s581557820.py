mod=10**9 + 7
n=int(input())
a=list(map(int,input().split()))
ans=0
total=sum(a)
for i in a:
  total -= i
  ans += total*i
print(ans%mod)