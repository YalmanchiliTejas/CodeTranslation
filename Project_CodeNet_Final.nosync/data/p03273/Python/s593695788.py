H,W = map(int,input().split())
A = []
for _ in range(H):
    a = list(input())
    if '#' in a:
        A.append(a)
    else:
        H -= 1

for i in range(W-1,-1,-1):
    ch = 0
    for j in range(H):
        if A[j][i] == '#':
            ch = 0
            break
        else:
            ch = 1
    if ch == 1:
        for k in range(H):
            del A[k][i]
    
for a in A:
    print(''.join(a))