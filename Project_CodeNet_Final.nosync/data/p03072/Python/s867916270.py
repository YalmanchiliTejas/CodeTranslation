n = int(input())
h = list(map(int, input().split()))

sum = 1

for i in range(1, n):
    max_height = max(h[:i])
    if (max_height <= h[i]):
        sum += 1
print(sum)