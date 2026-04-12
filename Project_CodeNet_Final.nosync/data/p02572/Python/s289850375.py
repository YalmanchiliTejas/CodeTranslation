n = int(input())
a = list(map(int, input().split()))
ruiseki = 0
count = 0
for i in range(n-1):
    ruiseki += a[i]
    count += ruiseki * a[i+1]
mod = 10**9 + 7
if count >= mod:
    print(count%mod)
else:
    print(count)