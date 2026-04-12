N = int(input())
A = list(map(int,input().split()))
total = sum(A)
ans = 0
for i in A:
    total-=i
    ans+=total*i
    ans%=(10**9+7)
print(ans)