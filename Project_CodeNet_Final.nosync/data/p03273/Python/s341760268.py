h, w = map(int, input().split())

A = []
for i in range(h):
    a = list(input())
    if '#' in a:
        A.append(a)
        
for i in range(w - 1, -1, -1):
    for j in range(len(A)):
        if A[j][i] == '#':
            break
    else:
        for k in range(len(A)):
            del A[k][i]
            
for a in A:
    print(''.join(a))