
n = int(input())
hs = map(int, input().split())

res = 0
mx = 0
for h in hs:
    if h >= mx:
        res += 1
    mx = max(h, mx)
print(res)