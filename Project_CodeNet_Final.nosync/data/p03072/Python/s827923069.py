n = int(input())
h = list(map(int, input().split()))
highest = 0
count = 0
for hi in h:
    if hi >= highest:
        highest = hi
        count += 1
print(count)