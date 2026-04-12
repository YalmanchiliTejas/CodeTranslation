import sys
y = input().split()
H = int(y[0])
W = int(y[1])
x = list()
for i in range(H):
    x.append(input())

flagH = list()
flagW = list()
for i in range(H):
    flagH.append(False)
for j in range(W):
    flagW.append(False)

for i in range(H):
    for j in range(W):
        if x[i][j] == "#":
            flagH[i] = True
            flagW[j] = True

for i in range(H):
    for j in range(W):
        if flagH[i] and flagW[j]:
            sys.stdout.write(x[i][j])
    if flagH[i]:
        print()