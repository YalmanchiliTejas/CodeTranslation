n = int(input())
x = [int(w) for w in input().split()]

ans = 0
mod = 10**9 + 7
s = sum(x)

for i in range(n):
    ans += ((x[i])**2)

ans = (s**2 - ans)//2
print(ans%mod)