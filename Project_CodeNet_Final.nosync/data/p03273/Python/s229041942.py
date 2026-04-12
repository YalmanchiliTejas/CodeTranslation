H, W = map(int,input().split())
B = []
for _ in range(H):
    line = input()
    for l in line:
        if l == "#":
            B.append(line)
            break;

White = []
for i in range(W):
    flag = True
    for j in range(len(B)):
        if B[j][i] == "#":
            flag = False
    if flag:
        White.append(i)

for i in range(len(B)):
    line = B[i]
    for i, l in enumerate(line):
        if i not in White:
            print(l,end="")
    print()
