a, b = map(int, input().split())
c = []
for i in range(a):
    c.append(list(input()))
x = y = 0
while True:
    c[x][y] = "."
    if x == a - 1 and y == b - 1:
        break
    d = False
    if x + 1 < a and not d:
        if c[x+1][y] == "#":
            d = not d
            x += 1
    if y + 1 < b and not d:
        if c[x][y + 1] == "#":
            d = not d
            y += 1
    if not d:
        print("Impossible")
        exit()
p = True
for i in range(a):
    if "#" in c[i]:
        print("Impossible")
        exit()
print("Possible")
