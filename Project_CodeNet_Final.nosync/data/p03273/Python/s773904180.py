h, w = map(int, input().split())

A = []
for i in range(h):
    s = list(input())
    if '#' in s:
        A.append(s)

h2 = len(A)
for j in range(w - 1, -1, -1):
    for i in range(h2):
        if A[i][j] == '#':
            break
        elif i == h2 - 1:
            for k in range(h2):
                del A[k][j]
            
for a in A:
    print(''.join(a))