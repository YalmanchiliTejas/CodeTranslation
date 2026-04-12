N = int(input())
A = [int(x) for x in input().split()]

mod = 10**9 + 7

ans = sum(A) * sum(A) % mod
ans += mod - (sum([a*a for a in A]) % mod)
ans %= mod
if(ans%2==0):
    ans //= 2
else:
    ans = (ans + mod) // 2
    ans %= mod
print(ans)