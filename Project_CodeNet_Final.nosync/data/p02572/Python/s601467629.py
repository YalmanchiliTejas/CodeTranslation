N = int(input())
A = list(map(int, input().split()))
mod = 1000000007
S = [0]*N
S[N-1] = A[N-1]
for i in range(N-2,0,-1):
    S[i] = int((S[i+1] + A[i])%mod)

sum = 0
for i in range(N-1):
    sum += int(A[i]*S[i+1]%mod)
    

sum = int(sum%mod)    
print(sum)