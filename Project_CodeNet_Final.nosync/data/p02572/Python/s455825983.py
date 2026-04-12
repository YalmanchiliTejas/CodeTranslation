from itertools import accumulate
n = int(input())
div = 10 ** 9 + 7
lst = list(map(int, input().split()))
ACC = list(accumulate(lst))
ACC.pop(n - 1)
res = 0
for i in range(n - 1):
  res += (lst[i + 1] * ACC[i])
  res %= div
print(res)