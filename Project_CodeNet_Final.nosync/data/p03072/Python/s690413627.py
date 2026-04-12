a = int(input())
b = list(map(int, input().split()))
c = 0
d = 0
for i in range(a):
    if b[i] >= c:
        d += 1
    c = max(c, b[i])
print(d)
