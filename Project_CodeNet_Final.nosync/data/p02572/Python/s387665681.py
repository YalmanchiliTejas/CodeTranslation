n=int(input())
a=list(map(int,input().split()))
MOD= 10**9 + 7
toki = [0]*(n+1)
shigi=0

toki[0] = sum(a)-a[0]
for i in range(1, n-1):
  toki[i] = toki[i-1]-a[i]
  
for i in range(n-1):
  shigi += (a[i] * toki[i])

print(shigi%MOD)