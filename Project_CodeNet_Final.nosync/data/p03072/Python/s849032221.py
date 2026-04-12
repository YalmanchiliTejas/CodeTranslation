n = int(input())
h = [int(i) for i in input().split()]
a = 0
highest = 0

for i in range(n):
    if h[i] >= highest:
        a += 1
        highest = h[i]

print(a)