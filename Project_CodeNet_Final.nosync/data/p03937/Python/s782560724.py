h, w = map(int, input().split()); a = [input() for _ in range(h)]; z = 0
for i in range(h):
    for j in range(w):
        if i == 0 and j == 0:
            if a[i+1][j] == "#" and a[i][j+1] == "#": print("Impossible"); z = 1; break
        elif i == h-1 and j == w-1:
            if a[i-1][j] == "#" and a[i][j-1] == "#": print("Impossible"); z = 1; break
        else:
            if a[i][j] == "#":
                x = y = 0
                if i != 0:
                    if a[i-1][j] == "#": x += 1
                if j != 0:
                    if a[i][j-1] == "#": x += 1
                if i != h-1:
                    if a[i+1][j] == "#": y += 1
                if j != w-1:
                    if a[i][j+1] == "#": y += 1
                if x != 1 or y != 1: print("Impossible"); z = 1; break
    if z == 1: break
else: print("Possible")