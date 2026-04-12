data_num = int(input())
data = list(map(int, input().split(" ")))

max_high = 0
count = 0
for high in data:
    if high >= max_high:
        count += 1
        max_high = high
print(count)