h, w = map(int, input().split())
blankw = [True] * w
blankh = [False] * h
data = []
for i in range(h):
    s = input()
    line = []
    if s.find("#") == -1:
        blankh[i] = True
    for j in range(w):
        line.append(s[j])
        if s[j] == "#":
            blankw[j] = False
    data.append(line)

for i in range(h):
    if blankh[i] is True:
        continue
    for j in range(w):
        if blankw[j] is True:
            continue
        print(data[i][j], end="")

    print("")