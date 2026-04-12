n = int(input())
h = list(map(int, input().split()))

c = 1
h_max = h[0]

for i in range(1, n):
    if h[i] >= h_max:
        c += 1
        h_max = h[i]

print(c)