from sys import stdin
n = int(stdin.readline().rstrip())
a = [int(x) for x in stdin.readline().rstrip().split()]
s = 0
t = 0
b = 0
m = 10 ** 9 + 7
for i in range(n):
    t += a[i]
    t = t % m
    b += a[i] ** 2
    b = b % m
s += int(((((t ** 2) % m + m - b) % m) * (5 * 10 ** 8 + 4)) % m)
print(s)