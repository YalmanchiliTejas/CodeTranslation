N = int(input())
A = list(map(int, input().split()))
mod = 1000000007
S = 0
for i in range(N):
    S += A[i]

sum = 0
for i in range(N):
    S -= A[i]
    if S<0:
        S+= mod
    sum += int(A[i]*S%mod)
    

sum = int(sum%mod)    
print(sum)