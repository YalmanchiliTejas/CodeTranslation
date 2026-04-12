n = int(input())
L = list(map(int,input().split()))
ans = 0
for i in range(1,n):
    if max(L[:i]) <= L[i]:
        ans += 1
print(ans+1)