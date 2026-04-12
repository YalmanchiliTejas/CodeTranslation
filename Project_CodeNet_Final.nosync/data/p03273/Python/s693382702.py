h, w = map(int, input().split())
A = [list(input()) for _ in range(h)]

temp = []
for i in range(h):
    if A[i] == ['.' for _ in range(w)]:
        temp.append(i - len(temp))
h -= len(temp)
for i in temp:
    A.pop(i)

B = []
for i in range(w):
    B_row = []
    for v in A:
        B_row.append(v[i])
    B.append(B_row)

temp = []
for i in range(w):
    if B[i] == ['.' for _ in range(h)]:
        temp.append(i - len(temp))
for i in temp:
    B.pop(i)
w -= len(temp)

C = []
for i in range(h):
    C_row = []
    for v in B:
        C_row.append(v[i])
    C.append(C_row)

for r in C:
    for c in r:
        print(c, end='')
    print()