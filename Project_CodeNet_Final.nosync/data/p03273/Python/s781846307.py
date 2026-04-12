H, W = map(int, input().split())
mas = []
deltags = []
for x in range(H):
    try:
        temp = list(input())
    except:
        pass
    if "#" in temp:
        mas.append(temp)

for x in range(len(mas[0])):
    deltag = False
    for y in range(len(mas)):
        if mas[y][x] == "#":
            break
        if y == len(mas)-1:
            deltag = True
    deltags.append(deltag)

for x in range(len(mas)):
    for y in range(len(mas[x])):
      if deltags[y]:
        mas[x][y] = "A"

try:
    x = 0
    while True:
        while "A" in mas[x]:
            mas[x].remove("A")
        print("".join(mas[x]))
        x += 1
except:
    pass
