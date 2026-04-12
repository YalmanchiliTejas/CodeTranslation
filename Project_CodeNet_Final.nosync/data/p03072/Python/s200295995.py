n = int(input())
h = [int(_) for _ in input().split()]
hmax = 0
count = 0

for hi in h:
    if hmax <= hi:
        hmax = hi
        count += 1
print(count)