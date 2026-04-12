N = int(input())
ls = list(map(int, input().split()))
mod = 10**9+7
total = sum(ls)
sq_power = sum(map(lambda x:x*x%mod, ls))
ans = (total**2 - sq_power)%mod
ans2 = 2
for _ in range(9):
    ans2 = (ans2**10)%mod
ans2 *= 2**5 % mod
print(ans*ans2%mod)