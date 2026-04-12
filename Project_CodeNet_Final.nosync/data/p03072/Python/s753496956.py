N = int(input())
H = list(map(int, input().split()))

ret = 0
mh = 0
for h in H:
    if mh <= h:
        ret += 1
        mh = h

print(ret)