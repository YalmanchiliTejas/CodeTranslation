n = int(input())
ar = list(map(int, input().split()))
s = sum(ar)
ans = 0
mod = 10 ** 9 + 7
ps = 0
for x in ar:
    ps += x
    ans = (ans + ((s - ps) * x) % mod) % mod
print(ans)
