n = int(input())
h = list(map(int, input().split()))

max = h[0]
count = 0

for i in range(n):
    if h[i] >= max:
        count = count + 1
        max = h[i]

print(count)