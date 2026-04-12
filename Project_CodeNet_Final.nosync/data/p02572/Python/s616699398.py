N = int(input())
A = list(map(int,input().split()))

sumA = sum(A)
ans = 0
for i in range(len(A)-1):
    sumA -= A[i]
    tmp1 = A[i] % (10**9 + 7)
    tmp2 = sumA % (10**9 + 7)
    ans += tmp1 * tmp2
    ans %= (10**9 + 7)
    
print(ans)