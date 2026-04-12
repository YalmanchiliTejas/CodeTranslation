n = int(input())
a = list(map(int,input().split()))
b = []
c = []
for i in range(n):
    if i % 2 == 0:
        b.append(a[i])
    if i % 2 == 1:
        c.append(a[i])
c.reverse()
c += b
if n % 2 == 1:
    c.reverse()
print(*c)