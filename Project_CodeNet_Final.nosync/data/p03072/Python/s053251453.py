_ = input()
hs = [int(i) for i in input().split(" ")]
res = 0
s = 0
for h in hs:
    if s <= h:
        s = h
        res += 1

print(res)