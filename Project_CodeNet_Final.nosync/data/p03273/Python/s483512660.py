import numpy as np
H,W = map(int, input().split(" "))
a = []
for h in range(H):
    a.append(list(input()))
A = np.array(a)
A = (A=="#")
for h in range(H):
    word = ""
    for w in range(W):
        if any(A[h]) and any(A.T[w]):
             if A[h][w]:
                 word += "#"
             else:
                 word += "."
    if word :print(word)
