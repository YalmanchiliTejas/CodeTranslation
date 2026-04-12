import bisect

N = int(input())

A = [0] * N
for i in range(N):
    A[i] = - int(input())

B = [A[0]]

for j in range(1,N):
    if B[-1] <= A[j]:
        B.append(A[j])
    else:
        B[bisect.bisect_right(B,A[j])] = A[j]
    #print(B)

print(len(B))