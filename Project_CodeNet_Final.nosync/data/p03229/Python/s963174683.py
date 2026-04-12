N = int(input())
A = list(int(input())for i in range(N))
A.sort()
L = []
R = []
for i in range(N):
    if i%2 == 0:
        L.append(A[i//2])
        R.append(A[-(i//2)-1])
    else:
        L.append(A[-(i//2)-1])
        R.append(A[i//2])
saL,saR = [],[]
for i in range(N):
    saL.append(abs(L[i]-L[i-1]))
    saR.append(abs(R[i]-R[i-1]))
print(max(sum(saL)-min(saL),sum(saR)-min(saR)))