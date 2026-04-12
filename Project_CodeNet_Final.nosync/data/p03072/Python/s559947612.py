n = int(input())
h = list(map(int, input().split()))
height = h[0]
counter = 0
for i in range(n):
    if h[i] >= height:
        counter += 1
        height = h[i]

print(counter)
