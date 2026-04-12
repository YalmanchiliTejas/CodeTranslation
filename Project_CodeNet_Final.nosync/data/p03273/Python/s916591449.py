H,W = [int(i) for i in input().split()]
A = [input() for _ in range(H)]
B = []
for i in range(H-1,-1,-1):
    if not "#" in A[i]:
        del A[i]
for i in range(W):
    flag = True
    for j in range(len(A)):
        if A[j][i] == "#":
            flag = False
    if flag:
        B.append(0)
    else:
        B.append(1)
for i in A:
    tmp = ""
    for j in range(len(i)):
        if B[j]:
            tmp+=i[j]
    print(tmp)