n = int(input())
H = list(map(int, input().split()))

count = 0
height = 0

for h in H:
    if h < height:
        continue
    else:
        count += 1
        height = h

print(count)