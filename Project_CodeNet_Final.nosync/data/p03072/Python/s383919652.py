N = int(input())
H = [int(a) for a in input().split()]

count = 0
max_height = -1

for h in H:
    if h >= max_height:
        count += 1
        max_height = h

print(count)