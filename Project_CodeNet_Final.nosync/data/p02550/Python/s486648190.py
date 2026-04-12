N, X, M = map(int,input().split())
A = [X]
As = set(A)
Lstart = 0
for i in range(N):
    An = A[-1]**2 % M
    if An in As:
        Lstart = A.index(An)
        break
    else:
        A.append(An)
        As.add(An)
LenBefL = Lstart
LenLoop = len(A) - Lstart
if LenLoop > 0:
    ans = sum(A[:Lstart])+sum(A[Lstart:])*((N-LenBefL)//LenLoop) + sum(A[Lstart:Lstart + (N-LenBefL)%LenLoop])
else:
    ans = sum(A)
print(ans)