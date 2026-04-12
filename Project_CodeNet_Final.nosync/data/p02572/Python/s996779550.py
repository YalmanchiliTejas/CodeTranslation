n = int(input())
a = list(map(int, input().split()))
s = sum(a)
t = 0
m = 10 ** 9 + 7
for i in range(n - 1):
    s -= a[i]
    t += a[i] * s % m
print(t % m)