N = int(input())
A = list(map(int, input().split()))

mod = int(1e+9 + 7)

rui = 0
for i in range(N):
    rui = (rui + A[i])%mod
    
answer = 0
for i in range(N-1):
    rui = (rui - A[i])%mod
    answer = (answer + rui * A[i])%mod
    
print(answer)