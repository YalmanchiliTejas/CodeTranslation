h, w = map(int, input().split())
a = [list(input()) + ["."] for _ in range(h)]
a.append(["."] * (w + 1))


i = 0
j = 0

while True:
    if a[i+1][j] == "#":
        a[i][j] = "."
        i += 1
    elif a[i][j+1] == "#":
        a[i][j] = "."
        j += 1
    else:
        break
a[i][j] = "."
bl = True
for row in a:
    if "#" in row:
        bl = False

ans = "Possible" if bl else "Impossible"
print(ans)
