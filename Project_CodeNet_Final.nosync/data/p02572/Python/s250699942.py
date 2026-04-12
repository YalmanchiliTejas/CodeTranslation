
N = int(input())
A = list(map(int,input().split()))

wa = sum(A)
out=0
for i in range(N):
    wa -= A[i]
    out+=A[i] * (wa)

print(out % (10**9 + 7))