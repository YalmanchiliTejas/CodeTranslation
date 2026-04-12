N = int(input())
Hs = [int(s) for s in input().split(' ')]
count = 0
m = 0
for h in Hs:
    if m > h:
        continue
    m = h
    count += 1
print(count)

