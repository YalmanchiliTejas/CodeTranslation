a = int(input())
b = list(map(int, input().split()))
c = 0
d = 0
for i in range(a):
    if c <= b[i]:
        d += 1
    if b[i] > c:
        c = b[i]
print(d)
