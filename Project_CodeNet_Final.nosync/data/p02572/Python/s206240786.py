N = int(input())
A = list(map(int,input().split()))
mod = 1000000000 + 7
add = 0
tmp = sum(A)
for i in range(N):
    tmp -= A[i]
    add += tmp * A[i]
print(add%mod)