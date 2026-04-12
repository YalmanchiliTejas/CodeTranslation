N,M = list(map(int,input().split()))
A = []
for i in range(N):
    B = list(input())
    if "#" in B: 
        A.append(B)
    else:
        pass
after_A = []
Fafter_A = []
for i in range(M):
    C = ""
    for j in range(len(A)):
        C += A[j][i]
    after_A.append(C)
for i in range(M):
    if "#" in after_A[i]: 
        Fafter_A.append(after_A[i])
    else:
        pass
for i in range(len(A)):
    D = ""
    for j in range(len(Fafter_A)):
        D += Fafter_A[j][i]
    print(D)