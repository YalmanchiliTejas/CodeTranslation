n = int(input())
lst = [int(input()) for _ in range(n)]
lst.sort()
center = n // 2
if n % 2:
  higher = lst[center + 1:]
  lower = lst[:center]
  ans = (sum(higher) - sum(lower)) * 2 - higher[0] + lower[-1] + max(lst[center] - lower[-1], higher[0] - lst[center])
else:
  higher = lst[center:]
  lower = lst[:center]
  ans = (sum(higher) - sum(lower)) * 2 - higher[0] + lower[-1]

print(ans)
