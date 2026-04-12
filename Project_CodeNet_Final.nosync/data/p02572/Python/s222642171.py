N=int(input())
A=list(map(int,input().split()))
all=0
sum=0
for i in range(N):
    all += A[i]
for i in range(N):
    all -= A[i]
    sum = (sum+A[i]*all) % (10**9+7)
print(sum)