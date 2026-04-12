t = [int(v) for v in input().split()]
isu = t[2]
count = 0
while isu <= t[0]:
    isu += t[1] + t[2]
    if isu > t[0]:
        break
    count += 1
print(count)