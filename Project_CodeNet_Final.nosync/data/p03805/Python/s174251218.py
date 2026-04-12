# coding: utf-8
# Your code here!
A = list(map(int,input().split()))
N = A[0]
M = A[1]

L = [[] for i in range(N)]
for i in range(M):
    X,Y = map(int,input().split()) 
    L[X-1].append(Y-1)
    L[Y-1].append(X-1)

#print(L)

def hitohudegaki(i,done):
    pattern = 0
    
    if i in done:
        return 0
    
    elif len(done) == N-1:
        return 1
    
    for j in range(len(L[i])):
        pattern += hitohudegaki(L[i][j],done+[i])
            
    return pattern



print(hitohudegaki(0,[]))
