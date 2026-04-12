n = int(input())
l = list(map(int, input().split()))
c = 1
s = []
for i in range(1, n):
    s = max(l[:i])
    if l[i] >= s:
        c += 1
print(c)
