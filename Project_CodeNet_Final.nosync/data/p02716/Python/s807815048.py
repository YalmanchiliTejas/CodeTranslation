n = int(input())
a = list(map(int,input().split()))
dp0 = 0
dp1 = 0
dp2 = 0
for i in range(1,n+1):
  ai = a[i-1]
  if i%2:
    dp1 = max(dp0,dp1)
    dp0 += ai
  if i%2 == 0:
    dp2 = max(dp1,dp2)
    dp1 += ai
  if i >= 3 and i%2:
    dp2 += ai
if n%2 == 0:
  print(max(dp0,dp1))
else:
  print(max(dp1,dp2))