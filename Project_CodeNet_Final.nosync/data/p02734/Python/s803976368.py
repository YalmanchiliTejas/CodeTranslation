n, s = map(int, input().split())
a = list(map(int, input().split()))
MOD = 998244353

ptn = [0] * (s + 1)
ptn[0] = 1
ans = 0
for i in range(n):
    for j in range(s + 1)[::-1]:
        if j + a[i] > s:
            continue
        ptn[j + a[i]] += ptn[j]
    ans += ptn[s]
    ans %= MOD
    ptn[0] += 1

print(ans)