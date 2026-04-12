MODINT = 1000000007
n = int(input())
A = list(map(int,input().split()))
prodsum = [0]*n
prodsum[0] = A[0]
for i in range(1,n):
    prodsum[i] = prodsum[i-1]+A[i]
# print(prodsum)
ans = 0
for i in range(n-1):
    ans += A[i]*(prodsum[-1]-prodsum[i])
print(ans%MODINT)
