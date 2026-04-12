na = lambda: list(map(int, input().split()))
h, w = na()
a = [input() for _ in range(h)]

migi = 0
ans = 1
for s in a:
    for cnt, i in enumerate(s):
        if cnt < migi and i == "#":
            ans = 0
        if i == "#":
            migi = cnt
print("Possible" if ans else "Impossible")