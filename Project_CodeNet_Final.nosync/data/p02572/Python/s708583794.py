N = int(input())
A = [int(T) for T in input().split()]
SumA = [0]*(N+1)
for TN in range(0,N):
    SumA[TN+1] = SumA[TN]+A[TN]
Sum = 0
Mod = 10**9+7
for TA in range(1,N):
    Sum += (A[TA]*SumA[TA])%Mod
print(Sum%Mod)