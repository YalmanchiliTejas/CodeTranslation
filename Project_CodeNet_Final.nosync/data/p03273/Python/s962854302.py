H, W = map(int, input().split())
A = []
for i in range(H):
    a = input()
    A.append(a)

h = []
w = []
for i in range(H):
    if A[i].count(".") == W:
        h.append(i)

for i in range(W):
    qwe = 0
    for j in range(H):
        if A[j][i] == ".":
            qwe += 1
        else:
            break
    if qwe == H:
        w.append(i)

p = 0
for i in h:
    A.pop(i-p)
    p += 1

p = 0
for i in w:
    i = i - p
    for j in range(len(A)):
        A[j] = A[j][:i] + A[j][i+1:]
    p += 1


for i in A:
    print(i)