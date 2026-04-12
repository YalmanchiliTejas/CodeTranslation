H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]
delJ = []
for j in range(W):
    judge = True
    for i in range(H):
        if A[i][j] == "#":
            judge = False
            break
    if judge:
        delJ.append(j)

output = []
for i in range(H):
    if "#" in A[i]:
        B = ""
        for j in range(W):
            if j not in delJ:
                B += str(A[i][j])
        output.append(B)

for i in output:
    print(i)