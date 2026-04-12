import numpy as np
h, w = map(int, input().split())

A = []
for i in range(h):
    s = list(input())
    if len(set(s)) == 1 and s[0] == ".":
        continue
    else:
        A.append(s)
B = A
c = 0
for i in range(w):
    s = []
    for j in range(len(A)):
        s.append(A[j][i])
    if len(set(s)) == 1 and s[0] == '.':
        B = np.delete(B, i-c, 1)
        c += 1


for i in B:
    a = ""
    for j in i:
        a += j
    print(a)