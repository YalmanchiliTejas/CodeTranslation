n = int(input())
mod = 10**9+ 7
a = list(map(int,input().split()))
ans = (sum(a)%mod)**2 - sum([x**2%mod for x in a])
ans *= 5*10**8+4
ans %= mod
print(ans)