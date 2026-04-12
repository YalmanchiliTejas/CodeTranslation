n = int(input())
a = list(map(int, input().split()))

sum_a = [0]
for v in a:
    sum_a.append(sum_a[-1] + v)

res = 0
mod = 10 ** 9 + 7
for i in range(n):
    res = (res + a[i] * sum_a[i] % mod) % mod

print(res)