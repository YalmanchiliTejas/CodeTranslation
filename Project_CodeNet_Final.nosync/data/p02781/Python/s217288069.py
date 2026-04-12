def two(n):
  n = str(n)
  top = int(n[0])
  b = len(n) - 1
  ans = b * (b-1) // 2 * 81 + (top-1) * b * 9 
  if b == 0:
    return 0
  for k,i in enumerate(n[1:],1):
    i = int(i)
    if i:
      ans += i + (b - k) * 9
      break
  return ans

n = int(input())
k = int(input())
if k == 1:
  n = str(n)
  top = int(n[0])
  ans = (len(n)-1) * 9 + top
  print(ans)
elif k == 2:
  n = str(n)
  top = int(n[0])
  b = len(n) - 1
  ans = b * (b-1) // 2 * 81 + (top-1) * b * 9 
  if b == 0:
    print(0)
    exit()
  for k,i in enumerate(n[1:],1):
    i = int(i)
    if i:
      ans += i + (b - k) * 9
      break
  print(ans)
elif k == 3:
  n = str(n)
  top = int(n[0])
  b = len(n) - 1
  if b <= 1:
    print(0)
    exit()
  ans = b * (b-1) * (b-2) // 6 * 729 + (top-1) * b * (b-1) // 2 *81
  n = int(n)
  t = n % (top * (10 ** b))
  mini_ans = two(t)
  ans += mini_ans
  print(ans)
