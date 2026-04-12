import sys
input = sys.stdin.readline
H, W = map(int, input().split())
S = [tuple(input()[:-1]) for _ in [0]*H]

ex = []
ey = []

for x in range(W):
    for s in S:
        if s[x] == '#':
            break
    else:
        ex.append(x)

for y in range(H):
    if '#' in S[y]:
        continue
    ey.append(y)

for y, s in enumerate(S):
    if y in ey:
        continue
    for x, t in enumerate(s):
        if x in ex:
            continue
        print(t, end="")
    print()
