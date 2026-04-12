h, w = map(int, input().split())

A = []
for i in range(h):
    s = list(input())
    if '#' in s:
        A.append(s)
        
B = [[0] * w for i in range(len(A))]
for i in range(len(A)):
    for j in range(w):
        if A[i][j] == '#':
            B[i][j] += 1
            
C = [0] * w
for i in range(len(A)):
    for j in range(w):
        C[j] += B[i][j]
        
D = [[] for i in range(len(A))]
for i in range(len(A)):
    for j in range(w):
        if C[j] != 0:
            D[i].append(A[i][j])
            
for i in range(len(A)):
    print(''.join(D[i]))        