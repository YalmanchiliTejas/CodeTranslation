n = int(input())
a = list(map(int,input().split()))
ruiseki = [0] * n
ruiseki[0] = a[0]
for i in range(1,n):
    ruiseki[i] += a[i] + ruiseki[i-1]
ans = 0
total = ruiseki[-1]
for i in range(n):
    ans += a[i] * (total-ruiseki[i])
print(ans%(10**9+7))