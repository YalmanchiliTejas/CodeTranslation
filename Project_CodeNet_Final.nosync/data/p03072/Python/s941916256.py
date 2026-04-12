
N = int(input())

Hn = list(map(int, input().split()))

minHigh = 0
counter = 0
for high in Hn:
    if high >= minHigh:
        counter += 1
        minHigh = high


print(counter)