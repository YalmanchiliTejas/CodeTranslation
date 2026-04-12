N = int(input())
A = list(map(int,input().split()))
A.reverse()
cum = []
cumsum = 0
for i in A:
    cum.append(cumsum+i)
    cumsum+=i
ans = 0
for j in range(N-1):
    ans += A[N-j-1]*cum[N-j-2]
    ans = ans%1000000007
print(ans)