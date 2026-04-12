h,w = map(int,input().split())
A = [list(input()) for i in range(h)]
B = []

for aa in A:
    flag = 0
    for a in aa:
        if a == "#":
            flag = 1
            break
    if flag:
        B.append(aa)

for i in range(w):
    flag = 1
    for j in range(len(B)):
        if B[j][i] == "#":
            flag = 0
            break
    if flag:
        for j in range(len(B)):
            B[j][i] = ""

[print("".join(b)) for b in B]