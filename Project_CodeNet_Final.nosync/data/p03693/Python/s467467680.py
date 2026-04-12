nums = list(map(str, input().split()))
s = "".join(nums)
n = int(s)
if n % 4 == 0:
  print("YES")
else:
  print("NO")