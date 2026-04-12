n = int(input())
h = list(map(int, input().split(' ')))
result = 1
max_h = h[0]
for i in range(1, n):
    if max_h <= h[i]:
        result += 1
        max_h = h[i]
    else:
        continue

print(result)