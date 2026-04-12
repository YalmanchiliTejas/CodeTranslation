n, x, m = map(int, input().split())
arr = [x]
mod = x
memo = [-1 for _ in range(m+1)]

ans = 0
for i in range(1, n):
    mod = mod ** 2 % m
    idx = memo[mod]

    if idx != -1:
        a = i - idx
        q, _mod = divmod((n - idx), a)

        ans = sum(arr[0:idx]) + q * sum(arr[idx:idx+a]) + sum(arr[idx:idx+_mod])
        break
    arr.append(mod)
    memo[mod] = i

if ans == 0:
    ans = sum(arr)

print(ans)