n = int(input())
h = [int(x) for x in input().split()]
c = 1

for i in range(1, n):
    if h[i] >= max(h[:i]):
        c += 1
print(c)
