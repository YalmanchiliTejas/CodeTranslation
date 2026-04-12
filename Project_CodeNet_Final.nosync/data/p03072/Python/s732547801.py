n = int(input())
x = 0
h = list(map(int, input().split()))
max = h[0]
for i in range(n):
    if max <= h[i]:
        x += 1
        max = h[i]
print(x)