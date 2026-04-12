n = int(input())
hight = input().split()
hight = [int(h) for h in hight]

maxH = 0
count = 0

for h in hight:
    if(maxH <= h):
        count += 1
        maxH = h

print(count)