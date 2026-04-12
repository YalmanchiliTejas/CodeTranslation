mod = 1000000007

n = int(input())
a = list(map(int, input().split(' ')))
b = [0] * (n + 1)

for i, v in enumerate(a):
    b[i+1] = (b[i] + v) % mod

ans = 0
for i in range(n):
    ans = (((a[i] * (b[n] - b[i+1])) % mod) + ans) % mod

print(ans)
