h, w = map(int, input().split())
a = [input() for _ in range(h)]
right_limit = [0]*h
for j in range(w):
    if a[0][j] == "#":
        right_limit[0] = j

for i in range(1, h):
    for j in range(w):
        if right_limit[i-1] > j and a[i][j] == "#":
            print("Impossible")
            exit()
        if a[i][j] == "#":
            right_limit[i] = j
print("Possible")