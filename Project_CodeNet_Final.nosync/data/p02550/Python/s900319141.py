import sys

input = sys.stdin.readline

n, x, m = map(int, input().split())

arr = [-1] * m
cumsum = [x]
a = x
for i in range(1, n):
    a *= a
    a %= m
    if arr[a] == -1:
        arr[a] = i
        cumsum.append(cumsum[-1] + a)
    else:
        di, mo = divmod(n - i, i - arr[a])

        ans = cumsum[-1]
        ans += di * (cumsum[-1] - cumsum[arr[a] - 1])
        ans += cumsum[arr[a] - 1 + mo] - cumsum[arr[a] - 1]
        break
else:
    ans = cumsum[-1]

print(ans)
