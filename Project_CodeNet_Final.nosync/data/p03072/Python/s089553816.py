N = int(input())
H = [int(s) for s in input().split()]
highest = 0
n = 0
for h in H:
    if h >= highest:
        highest = h
        n += 1
print(n)