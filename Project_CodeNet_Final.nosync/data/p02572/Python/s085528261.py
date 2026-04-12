
n = int(input())
# n = 2 * 10**4
# a = [i for i in range(n)]
a = list(map(int, input().split(" ")))

wari = 10**9 + 7

ruiseki = [0]
for i, ai in enumerate(a):
    ruiseki.append(ruiseki[i] + ai)

ans = 0
for i in range(n):
    ans += a[i] * (ruiseki[n] - ruiseki[i+1])
    ans = ans % wari

print(ans)

