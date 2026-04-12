H, W = map(int,input().split())
l = []
for h in range(H):
    s = list(input())
    if s != ["."]*W:
        l.append(s)

for w in range(W-1, -1, -1):
    cnt = 0
    for h in range(len(l)):
        if l[h][w] == "#":
            break
        else:
            cnt += 1
    if cnt == len(l):
        for h in range(len(l)):
            del l[h][w]
for h in range(len(l)):
    print("".join(l[h]))
        