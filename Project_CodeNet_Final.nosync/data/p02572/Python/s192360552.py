mod = 10**9 + 7
  
N = int(input())
A = [int(i)%mod for i in input().split()][:N]

wa = sum(A)

total = 0
for n in range(N-1):
    wa -= A[n]

    total += A[n] * wa
    total %= mod

print(total)