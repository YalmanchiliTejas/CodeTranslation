N=int(input())
A = tuple(map(int,input().split(" ")))
ans = 0

sum_ = sum(A)
for i in range(N):
    sum_ -= A[i]
    ans += sum_ * A[i]

print(ans % ( (10**9)+7) )