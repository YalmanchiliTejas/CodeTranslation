n = int(input())
a = tuple(map(int,input().split()))
MOD = 10**9+7

N = 2
FAC = [1]
INV = [1]
for i in range(1,N+1):
  FAC.append((FAC[i-1]*i) % MOD)
  INV.append(pow(FAC[-1],MOD-2,MOD))
#print(INV[2])
  
s = 0
for ai in a:
  s += ai
  s %= MOD
ans = 0
for ai in a:
  ans += ai*(s-ai)
  ans %= 10**9+7
print((ans*INV[2])%MOD)
#print((10**9)**2%MOD)