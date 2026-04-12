def transpose(A):
    B = []
    for j in range(len(A[0])):
        C = [A[i][j] for i in range(len(A))]
        B.append(C)
    return B

H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

for i in reversed(range(H)):
    if A[i] == ['.']*W:
        A.pop(i)
        
H = len(A)        
A = transpose(A)
for j in reversed(range(W)):
    if A[j] == ['.']*H:
        A.pop(j)

A = transpose(A)
for i in range(len(A)):
 	print(*A[i], sep='')