n, x, mod = map(int, input().split())

dp = [None]*mod

a = x
arr = [a]

for i in range(n-1):
  if dp[a] is not None:
    idx = arr.index(a)
    sum_early = sum(arr[:idx])
    cycle = i - idx
    sum_repeat = sum(arr[idx:-1])
    repeat_num = (n - idx) // cycle
    end_num = (n - idx) % cycle
    sum_end = sum(arr[idx:idx+end_num])
    ans = sum_early + sum_repeat*repeat_num + sum_end
    print(ans)
    exit()
  tmp = pow(a, 2, mod)
  dp[a] = tmp
  a = tmp
  arr.append(a)

print(sum(arr))