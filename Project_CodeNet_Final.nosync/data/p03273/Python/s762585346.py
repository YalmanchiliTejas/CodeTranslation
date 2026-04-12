h, w = [int(i) for i in input().split()]
a = [["." for i in range(w)] for j in range(h)]
out = []
for i in range(h):
    a[i] = input()
    for j in range(w):
        if a[i][j] == "#":
            out.append(a[i])
            break

out2 = ["" for j in range(len(out))]
blankLine = ""
for i in range(len(out)):
    blankLine += "."
for j in range(w):
    strTmp = ""
    for i in range(len(out)):
        strTmp += out[i][j]
    if strTmp != blankLine:
        for i in range(len(out)):
            out2[i] += out[i][j]
for i in range(len(out2)):
    print(out2[i])