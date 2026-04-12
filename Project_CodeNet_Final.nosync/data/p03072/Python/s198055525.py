A = int(input())

hi = list(map(int, input().split()))
max = hi[0]
count = 0
for h in hi:
    if max <= h:
        count += 1
        max = h
print(count)