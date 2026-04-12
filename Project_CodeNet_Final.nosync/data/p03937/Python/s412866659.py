H, W = map(int, input().split())

A = []

for i in range(H):
    tmp = input()
    A.append(tmp)
    
c = 0
    
for i in range(H):
    for j in range(W):
        if A[i][j]=='#':
            c = c+1
            
if not c==H+W-1:
    print('Impossible')
else:
    print('Possible')