import sys
readline = sys.stdin.readline

MOD = 10**9+7

N = int(readline())
A = list(map(int, readline().split()))

res = 0
res2 = 0
for a in A:
    res = (res + a)%MOD
    res2 = (res2 + a*a)%MOD


print(pow(2, MOD-2, MOD)*(res**2 - res2)%MOD)