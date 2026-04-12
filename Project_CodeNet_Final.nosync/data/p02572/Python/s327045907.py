N=int(input())
A=list(map(int,input().split()))
sumA = sum(A)
ans = 0
for i in range(N-1):
    x = A[i]
    sumA -= x
    ans += sumA*x
print(ans%((10**9)+7))
