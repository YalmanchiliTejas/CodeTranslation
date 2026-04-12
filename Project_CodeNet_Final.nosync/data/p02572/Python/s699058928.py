n=int(input())
a=list(map(int,input().split()))
p=10**9+7
suma = [0]*n
suma[0] = 0
for i in range(1,n):
  suma[i] = (suma[i-1] + a[i-1])%p

ans = 0
for i in range(n):
  ans = (ans + ((a[i] % p) * suma[i])%p)%p
print(ans)