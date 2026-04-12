N = int(input())
A = [int(T) for T in input().split()]
RevA = A[::-1]
SumA = [0]*(N+1)
for TN in range(0,N):
    SumA[TN+1] = SumA[TN]+RevA[TN]
SumA = SumA[::-1]
Sum = 0
Mod = 10**9+7
for TA in range(1,N):
    Sum += (A[TA-1]*SumA[TA])%Mod
print(Sum%Mod)