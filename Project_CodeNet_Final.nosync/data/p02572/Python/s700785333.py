n = int(input())
a = list(map(int, input().split(" ")))
mod = 10 ** 9 + 7
s = 0
for i in range(n):
    s = (s + a[i])
s = (s * s)
for i in range(n):
    s = (s - (a[i] ** 2) )
s = (s // 2) %mod
print(s)
