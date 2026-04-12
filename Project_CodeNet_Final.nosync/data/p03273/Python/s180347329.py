h, w = map(int, input().split())

lall = list()
for i in range(h):
    l = list(input())
    if l != ["."] * w:
        lall.append(l)

for i in range(w):
    j = 0
    while j < len(lall) and i < len(lall[j]) and lall[j][i] == ".":
        j += 1
        if j == len(lall):
            for k in range(len(lall)):
                lall[k][i] = "0"
            break    

for i in range(len(lall)):
    print(''.join([j for j in lall[i] if j != "0"]))
