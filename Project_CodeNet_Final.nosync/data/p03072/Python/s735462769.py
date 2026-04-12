n = int(input())
h = list(map(int, input().split()))
highest = 0
counter = 0

for i in range(n):
    if h[i] >= highest:
        counter += 1
        highest = h[i]

print(counter)