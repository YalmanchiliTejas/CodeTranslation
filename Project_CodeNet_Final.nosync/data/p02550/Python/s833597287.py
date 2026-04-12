from collections import defaultdict
n, x, m = list(map(int, input().split()))
dp = [False]*(m+1)
a = [0]*(m+1)
d = defaultdict(lambda: set())
flag = False
for i in range(1, min(m+1, n+1)):
    if i == 1:
        a[i] = x
        dp[x] = True
    else:
        a[i] = a[i-1]**2 % m
        if not dp[a[i]]:
            d[a[i-1]] = a[i]
            dp[a[i]] = True

        else:
            startv = a[i]
            flag = True

            break
start_idx = a[1:].index(a[i])+1
loop_haba = i-start_idx
loop_sum = sum(a[start_idx:i])
if not flag:
    print(sum(a[:n+1]))
else:
    ans = sum(a[:(start_idx)])

    ans += ((n-start_idx)//loop_haba)*loop_sum
    ans += sum(a[start_idx: start_idx+((n-start_idx) % loop_haba)+1])
    print(ans)
