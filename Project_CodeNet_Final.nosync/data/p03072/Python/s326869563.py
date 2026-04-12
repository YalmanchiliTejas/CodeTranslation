n = int(input())
hs = list(map(int, input().split()))

count, max_h = 0, 0
for h in hs:
    if h >= max_h:
        max_h = h
        count += 1

print(count)