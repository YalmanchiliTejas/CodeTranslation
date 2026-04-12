import sys
input = sys.stdin.readline
ins = lambda: input().rstrip()
ini = lambda: int(input().rstrip())
inm = lambda: map(int, input().split())
inl = lambda: list(map(int, input().split()))

h, w = inm()
grid = []
for i in range(h):
    s = ins()
    if "#" in s:
        grid.append(list(s))
remove = []
for i in range(w):
    tmp = True
    for x in grid:
        if x[i] == "#":
            tmp = False
            break
    if tmp:
        remove.append(i)
for i in remove[::-1]:
    for x in grid:
        x.pop(i)
for i in grid:
    print("".join(i))