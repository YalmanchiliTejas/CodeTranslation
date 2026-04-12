N = int(input())
mountain_list = list(map(int, input().split()))
highest = 0
count = 0
for x in mountain_list:
    if x >= highest:
        count += 1
        highest = x

print(count)