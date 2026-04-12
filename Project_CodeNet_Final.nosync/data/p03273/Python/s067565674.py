h, w = map(int,input().split())
maps = [None]*h
for i in range(h):
    maps[i] = input()
hashes = []
for i in range(h):
    if "#" in maps[i]:
        hashes.append(i)
white = []
for i in range(w):
    flag = 0
    for j in range(h):
        if maps[j][i] == "#":
            flag = 1
    if flag == 1:
        white.append(i)
for i in hashes:
    for j in white:
        print(maps[i][j],end="")
    print()