h, w = map(int, input().split())

A = []
for i in range(h):
    a = list(input())
    if '#' in a:
        A.append(a)
        
for j in range(w - 1, -1, -1):
    for i in range(len(A)):
        if A[i][j] == '#':
            break
    else:
        for k in range(len(A)):
            del A[k][j]
            
for i in range(len(A)):
    print(''.join(A[i]))