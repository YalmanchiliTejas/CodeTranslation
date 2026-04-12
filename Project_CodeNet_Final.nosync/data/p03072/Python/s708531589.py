n = int(input())
h = list(map(int, input().split()))
count = 0
max_h = 0
for i in range(n):
    if h[i] >= max_h:
        count += 1
        max_h = h[i]
print(count)