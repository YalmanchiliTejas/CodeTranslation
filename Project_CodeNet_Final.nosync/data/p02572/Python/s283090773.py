MOD = 10 ** 9 + 7
 
N = int(input())
a = list(map(int,input().split()))
 
ans = 0
ans = sum(a) * sum(a) % MOD
ans -= sum(map(lambda x:x * x,a)) % MOD
ans %= MOD
if ans % 2 == 0:
    print(ans // 2)
else:
    print((ans + MOD) // 2)