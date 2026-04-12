N = int(input())
A = list(map(int,input().split()))
ans = 0
s = sum(A[1:])
for i in range(N-1):
    ans += A[i]*s 
    s = s - A[i+1]
print(ans % (10**9+7))