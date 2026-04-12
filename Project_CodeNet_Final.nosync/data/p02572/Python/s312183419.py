a = int(input())
alist = list(map(int, input().split()))
mod = 10**9+7
total = sum(alist)
sumlist = []
ans = 0
for i in range(len(alist)-1):
    total -= alist[i]
    ans += alist[i]*(total)
print(ans%mod)