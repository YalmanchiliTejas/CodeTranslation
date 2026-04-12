import sys

def checkCol(A, i):
    for j in range(len(A[i])):
        if A[i][j] == "#":
            return False
    return True

def checkLow(A, j):
    for i in range(len(A)):
        if A[i][j] == "#":
            return False
    return True

H, W = map(int, sys.stdin.readline().strip().split(" "))

A = []
for line in sys.stdin:
    A.append(list(line.strip()))

col = []
low = []
for i in range(len(A)):
    if checkCol(A, i):
        col.append(i)

for i in range(len(A[0])):
    if checkLow(A, i):
        low.append(i)

for i, al in enumerate(A):
    if i in col:
        continue
    for j, a in enumerate(A[i]):
        if j in low:
            continue
        sys.stdout.write(a)
    sys.stdout.write("\n")

