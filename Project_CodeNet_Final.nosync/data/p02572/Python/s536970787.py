N = int(input())
A = list(map(int,input().split()))
total_prod=sum(A)
ans = 0
for i in A[:-1]:
    total_prod=total_prod-i
    ans += total_prod*i
print(ans%(10**9+7))