N = int(input())
hotel = list(map(int, input().split()))
count = 0
max_h = 0
for h in hotel:
    if max_h <= h:
        max_h = h
        count += 1

print(count)
