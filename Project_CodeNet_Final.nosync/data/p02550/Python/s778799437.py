N, X, M = map(int,input().split())

exist = [False] * M 
exist[X] = True

A = [X]

while True:
    nex = A[-1]*A[-1] % M
    A.append(nex)
    if exist[nex]:
        break
    else:
        exist[nex] = True

L = len(A)
idx = 0
for i in range(L):
    if A[i] == A[-1]:
        idx = i
        break

ans = 0
for i in range(idx):
    ans += A[i]
    N -= 1
    if(N < 0): exit()

B = A[idx:(L-1)]

ans += (sum(B)*(N//len(B)) + sum(B[:(N%len(B))]))
print(ans)



