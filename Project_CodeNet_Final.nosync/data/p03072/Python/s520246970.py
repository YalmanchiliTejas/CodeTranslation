n = int(input())
h = list(map(int, input().split()))

c = 0
for i in range(n):
    if i == 0:
        c += 1
    elif h[i] >= max(h[0:i]):
        c += 1

print(c)