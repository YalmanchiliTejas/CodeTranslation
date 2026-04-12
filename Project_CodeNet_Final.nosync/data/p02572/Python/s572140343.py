n = int(input())
a = list(map(int, input().split()))

s = 0
for i in range(n):
    s += a[i]

tr = 0
for i in range(n):
    tr += a[i] ** 2

a2 = s ** 2 - tr
a = a2 // 2
a %= 10 ** 9 + 7

print(a)