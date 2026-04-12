#template
def inputlist(): return [int(j) for j in input().split()]
#template

mod = 10**9 + 7
N = int(input())
A = inputlist()

s = sum(A)
ans = 0
for i in range(N):
    s -= A[i]
    ans += A[i]*s
    ans %= mod
print(ans)