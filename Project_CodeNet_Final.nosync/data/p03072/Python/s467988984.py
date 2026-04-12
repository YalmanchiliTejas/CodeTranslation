n = int(input())
h = [int(item) for item in input().split()]

max_h = 0 
count = 0
for i, item in enumerate(h):
    if i == 0:
        max_h = item
        count += 1
    else:
        if item >= max_h:
            max_h = item
            count += 1
print(count)