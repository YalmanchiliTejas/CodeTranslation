n = int(input())
h = list(map(int, input().split()))

count = 0
Max = h[0]
for i in range(n):
    if Max <= h[i]:
        Max = h[i]
        count += 1
print(count)