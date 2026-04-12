N = int(input())
hotels = [int(i) for i in input().split()]
count = 0
max_height = 0
for i in range(len(hotels)):
    if i == 0:
        count += 1
        max_height = hotels[0]
    else:
        if hotels[i] >= max_height:
            count += 1
            max_height = hotels[i]
print(count)
