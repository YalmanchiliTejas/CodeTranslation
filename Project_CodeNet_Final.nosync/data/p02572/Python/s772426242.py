n=int(input())
a=list(map(int,input().split()))

s=[0]*(n+1)
for i in range(n):
  s[i+1] = s[i] + a[i]

MOD = 10**9+7
result = 0
for i in range(n):
  result += a[i]*(s[n] - s[i+1])%MOD
print(result%MOD)

