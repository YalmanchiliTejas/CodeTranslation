n = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7
ans = 0
s = sum(a)
for i in a:
    s -= i
    ans = (ans + (i * s))
ans = ans % mod
print(ans)