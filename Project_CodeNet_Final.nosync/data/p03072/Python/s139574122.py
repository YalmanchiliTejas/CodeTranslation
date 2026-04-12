n = int(input())
hs = map(int, input().split())
l = -1
ret = 0
for h in hs:
    if h >= l:
        ret += 1
        l = h
print(ret)
