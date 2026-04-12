n = int(input())
h = list(map(int, input().split()))
highest = 0
count = 0
for i in range(n):
    if h[i] >= highest:
        highest = h[i]
        count += 1
print(count)