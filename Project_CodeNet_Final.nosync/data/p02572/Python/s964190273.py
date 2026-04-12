N = int(input())
A = list(map(int,input().split()))

sum = 0
B = []
B.append(0)

for t in range(N):
    B.append(A[t] + B[t])
    
B.remove(0)
    
for i in range(N):
    sum += A[i] * (B[N-1] - B[i])
        
print(sum % (10**9+7))