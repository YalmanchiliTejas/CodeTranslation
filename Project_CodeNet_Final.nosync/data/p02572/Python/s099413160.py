n = int(input())
arr = [int(x) for x in input().split(' ')]

pre = []

for x in arr:
    if len(pre) == 0:
        pre.append(x)
    else:
        pre.append(pre[len(pre)-1] + x)
        
ans = 0
mod=int(1e9+7)
for i in range(n):
    s = (pre[n - 1] - pre[i]) * arr[i]
    ans = ((ans % mod) + s % mod) % mod
    
print(ans)
    