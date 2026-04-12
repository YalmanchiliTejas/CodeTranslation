N = int(input())
A = list(map(int,input().split()))
X = sum(A)
out = 0
p = 10**9+7
for i in range(N-1):
    X = X-A[i]
    out =  (out+A[i]*X)%p
print(out)
