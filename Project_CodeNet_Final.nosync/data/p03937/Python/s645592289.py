h, w  = map(int, input().split())
a = [input() for _ in range(h)]

memo = [[0] * w for _ in range(h)]

i = 0
j = 0
memo[i][j] = 1
while i < h-1 and j < w-1:
    if a[i+1][j] == "#" and a[i][j+1] == "#":
        print("Impossible")
        exit()
    elif a[i+1][j] == "#":
        i += 1
        memo[i][j] = 1
    elif a[i][j+1] == "#":
        j += 1
        memo[i][j] = 1
    else:
        print("Impossible")
        exit()

if i == h-1:
    while j < w-1:
        if a[i][j+1] == ".":
            print("Impossible")
            exit()
        j += 1
        memo[i][j] = 1
else:
    while i < h-1:
        if a[i+1][j] == ".":
            print("Impossible")
            exit()
        i += 1
        memo[i][j] = 1

for i in range(h):
    for j in range(w):
        if a[i][j] == "#" and memo[i][j] == 0:
            print("Impossible")
            exit()

print("Possible")