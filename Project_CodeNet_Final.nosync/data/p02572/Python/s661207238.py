n = int(input())
a = list(map(int, input().split()))

s_1 = 0
s_2 = 0
m = 10 ** 9 + 7
for i in range(n):
    s_1 += a[i] % m
    s_2 += (a[i] ** 2) % m
s = (s_1 * s_1 - s_2) * pow(2, m - 2) % m
print(s)