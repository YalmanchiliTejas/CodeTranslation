N = int(input())
A = []

for i in range(N):
    A.append(int(input()))

A = sorted(A)

B = [0] * N
m = int(N/2)
B[m] = A[0]

si = 1
bi = 0
ci = 1

for i in range(1, N):
    si *= -1
    ii = int(i/2 + 0.5)

    if i % 4 == 1 or i % 4 == 2:
        B[m+si*ii] = A[N-bi-1]
        bi += 1
    if i % 4 == 3 or i % 4 == 0:
        B[m+si*ii] = A[ci]
        ci += 1

C = [0] * N
m = int(N/2)
C[m] = A[N-1]

si = 1
bi = 1
ci = 0

for i in range(1, N):
    si *= -1
    ii = int(i/2 + 0.5)

    if i % 4 == 1 or i % 4 == 2:
        C[m+si*ii] = A[ci]
        ci += 1
    if i % 4 == 3 or i % 4 == 0:
        C[m+si*ii] = A[N-bi-1]
        bi += 1

cntB = 0
cntC = 0
for i in range(N-1):
    cntB += abs(B[i] - B[i+1])
    cntC += abs(C[i] - C[i+1])


print(max(cntB, cntC))
