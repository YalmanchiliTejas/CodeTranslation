n = int(input())
a = [int(i) for i in input().split()]
c = 1
m = a[0]
for i in range(1, n):
    m = max(m, a[i])
    if m == a[i]:
        c += 1
print(c)