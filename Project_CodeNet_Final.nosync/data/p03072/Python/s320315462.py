n = int(input())

hotels = [int(c) for c in input().split()]

count = 1
highest = hotels[0]
for i in range(1, len(hotels)):
    if highest <= hotels[i]:
        count += 1
        if highest < hotels[i]:
            highest = hotels[i]

print(count)