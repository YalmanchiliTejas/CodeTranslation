n = int(input())
h = list(map(int, input().split()))
total = 1
max_value = h[0]
for i in range(1, n):
    if max_value <= h[i]:
        total += 1
    max_value = max(max_value, h[i])
print(total)
