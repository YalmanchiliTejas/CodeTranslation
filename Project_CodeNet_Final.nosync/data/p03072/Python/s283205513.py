n = int(input())
mountains = list(map(int, input().split()))
highest = mountains[0]
counts = 1
for i in range(1, len(mountains)):
    if mountains[i] >= highest:
        counts += 1
        highest = mountains[i]
print(counts)
