n = int(input())
h = list(map(int, input().strip().split(' ')))
high = 0
c = 0
for i in range(n):
    if h[i] >= high:
        high = h[i]
        c = c + 1
print(c)