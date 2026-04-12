N = int(raw_input())
H = map(int, raw_input().split())

limit, count = 0, 0
for h in H:
    if h >= limit:
        count += 1
    limit = max(limit, h)

print count