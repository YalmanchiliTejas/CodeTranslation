n = int(input())
l = list(map(int,input().split()))
x = [*l]
ans = 0
mod = 1000000007
for i in range(1,n):
  l[i] += l[i-1]
i = 0
while i<n-1:
  ans += (x[i])*(l[n-1] - l[i])
  i += 1
print(ans%mod)
