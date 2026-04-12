n, x, mod = map(int, input().split())
lst = [0, x]
num_set = set([x])
num_lst = [0, x]
flag = False

for i in range(mod - 1):
  x = (x * x) % mod
  s = x + lst[-1]
  if x == 0:
    lst.append(s)
    break
  if x in num_set:
    flag = True
    break
  lst.append(s)
  num_set.add(x)
  num_lst.append(x)
  if i + 2 == n:
    break

#print(lst)
if flag:
  for i, ele in enumerate(num_lst):
    if x == ele:
      loop_s = i
      break

l = len(lst)
if lst[l - 1] == lst[l - 2]:
  print(lst[l - 1])
else:
  if not flag:
    print(lst[-1])
  else:
    loop = len(lst) - loop_s
    n -= loop_s - 1
    c = n // loop
    r = n % loop
    ans = lst[l - 1] + (c - 1) * (lst[l - 1] - lst[loop_s - 1]) + lst[loop_s + r - 1] - lst[loop_s - 1]
    print(ans)
