H, W = list(map(int, input().split()))
A = []
for i in range(H):
    a = input()
    if set(a) != set('.'):
        A.append(a)

H = len(A)
A2 = []
for i in range(W):
    a = ''
    for j in range(H):
        a += A[j][i]
    if set(a) != set('.'):
        A2.append(a)

H = len(A2)
W = len(A2[0])
A = []
for i in range(W):
    a = ''
    for j in range(H):
        a += A2[j][i]
    A.append(a)

for a in A:
    print(a)