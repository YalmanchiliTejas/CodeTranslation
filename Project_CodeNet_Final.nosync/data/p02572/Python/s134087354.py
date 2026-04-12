n = int(input())
alist = list(map(int,input().split()))

mod = 10**9 + 7
sum = alist[0]
ans = 0
for i in range(n-1):
    ans = (ans + sum*alist[i+1]) % mod
    sum = (sum + alist[i+1]) % mod

print(ans)