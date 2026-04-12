import numpy as np

H, W = (int(i) for i in input().split())

A = [["" for i in range(W)] for j in range(H)]

for i in range(H):
    tmp = list(input())
    for j in range(W):
        A[i][j] = tmp[j]

hlist = []
wlist = []

for i in range(H):
    if "#" not in A[i]:
        hlist.append(i)

for j in range(W):
    tmp = []
    for i in range(H):
        tmp.append(A[i][j])
    if "#" not in tmp:
        wlist.append(j)

# print(hlist)
# print(wlist)

for i in hlist:
    for j in range(W):
        A[i][j] = 0

for j in wlist:
    for i in range(H):
        A[i][j] = 0

for i in range(H):
    while True:
        if 0 in A[i]:
            A[i].remove(0)
        else:
            break

while True:
    if [] in A:
        A.remove([])
    else:
        break

for li in A:
    print("".join(li))