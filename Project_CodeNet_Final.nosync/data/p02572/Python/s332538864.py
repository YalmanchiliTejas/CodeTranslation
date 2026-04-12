n = int(input())
a = list(map(int, input().split()))
mod = 10 ** 9 + 7

pa = [0]
for i in a:
    pa.append(i + pa[-1])

ans = 0
for i, v in enumerate(a):
    ans += (v * (pa[-1] - pa[i + 1])) % mod
    ans %= mod
print(ans)
