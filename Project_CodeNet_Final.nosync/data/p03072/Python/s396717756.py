N = int(input())
yamas = [int(j) for j in input().split()]
highest = 0
mountains = 0

for i in range(N):
    if yamas[0] >= highest:
        mountains += 1
        highest = yamas[0]
        yamas = yamas[1:]
    else:
        yamas = yamas[1:]

print(mountains)
