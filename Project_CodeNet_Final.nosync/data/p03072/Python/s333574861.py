n = int(input())
h = list(map(int, input().split()))
highest = 0
counter = 0

for mt in h:
    if mt >= highest:
        highest = mt
        counter += 1
print(counter)
