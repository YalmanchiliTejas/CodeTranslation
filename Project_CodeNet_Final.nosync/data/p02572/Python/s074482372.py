n = int(input())
a = list(map(int, input().split()))
ans = 0
r_wa = [a[0]]
for i in range(n) :
  if i>0 :
    r_wa.append(r_wa[i-1]+a[i])

for i in range(n-1) :
  ans += a[i]*(r_wa[n-1]-r_wa[i])
  ans = ans%1000000007
print(ans)