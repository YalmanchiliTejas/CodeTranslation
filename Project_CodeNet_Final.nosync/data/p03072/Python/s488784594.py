n = int(input())
h = list(map(int, input().split()))
c = 1
for i in range(1, n):
    if max(h[:i]) <= h[i]:
        c += 1
print(c)