h, w = map(int, input().split())
t = []
goodx = [0]*110
goody = [0]*110

for i in range(h):
    t.append(input())

for i in range(h):
    for j in range(w):
        if t[i][j] == "#":
            goodx[i] = 1
            goody[j] = 1

for i in range(h):
    if goodx[i]:
        for j in range(w):
            if goody[j]:
                print(t[i][j], end="")
        print()