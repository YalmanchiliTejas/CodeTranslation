N = int(input())
Hs = map(int, input().split())

count = 0
highest = 0
for H in Hs:
    if H >= highest:
        count += 1
    highest = max(highest, H)

print(count)