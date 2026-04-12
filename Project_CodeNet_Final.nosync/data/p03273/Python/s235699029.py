H, W = map(int, input().split())

A = []
for i in range(H):
    s = input()
    if '#' in s:
        A.append(list(s))

H = len(A)
B = []
for i in range(W):
    s = []
    for j in range(H):
        s.append(A[j][i])
    if "#" in s:
        B.append(s)

W = len(B)
for i in range(H):
    s = ""
    for j in range(W):
        s += B[j][i]
    print(s)
