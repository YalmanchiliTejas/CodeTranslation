n = int(input())
hh = map(int, input().split())

prev = 0
ret = 0
for h in hh:
    if prev <= h:
        ret += 1
    else:
        pass

    prev = max(prev, h)

print(ret)
