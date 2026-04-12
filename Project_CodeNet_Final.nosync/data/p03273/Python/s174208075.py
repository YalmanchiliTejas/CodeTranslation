# encoding: utf-8
H, W = map(int, input().split())
a = [input() for i in range(H)]

a2 = []
for item in a:
    if item == "." * W: continue
    a2.append(item)

white = []
for j in range(W):
    for item in a2:
        if item[j] == "#": break
        else: continue
    else:
        white.append(j)

a3 = []
for item in a2:
    line = ""
    for j in range(W):
        if j in white: continue
        line += item[j]
    a3.append(line)

for item in a3: print(item)
