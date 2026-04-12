n = int(input())
l = [int(I) for I in input().split()]
r = 0
m = 0
for i in range(n):
    a = l[i]
    if m <= a:
        r += 1
        m = a
print(r)