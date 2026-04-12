h, w = map(int, input().split())

g = []
cnt = 0
for _ in range(h):
    a = input() + "?"
    cnt += a.count("#")
    g.append(list(a))

if cnt != h+w-1:
    print("Impossible")
    exit()

g.append(["?"]*w)

y, x = 0, 0

for _ in range(h+w-2):
    if g[y+1][x] == "#" and g[y][x+1] != "#":
        y += 1
    elif g[y][x+1] == "#" and g[y+1][x] != "#":
        x += 1
    else:
        print("Impossible")
        exit()
print("Possible")