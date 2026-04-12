n = int(input())
a = list(map(int, input().split()))
st=10**9+7
ans = 0
s = sum(a)-a[0]
for i in range(n-1):
  ans+=(a[i]*s)
  ans%=st
  s-=a[i+1]
print(ans)
