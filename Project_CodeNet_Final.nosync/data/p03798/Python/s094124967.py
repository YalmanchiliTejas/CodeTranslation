N = int(input())
s = input()
l = [1] * N

# S: 1, W: 0
for a0, a1 in ((0, 0), (0, 1), (1, 0), (1, 1)):
  l[0] = a0
  l[1] = a1

  for i in range(1, N - 1):
    if s[i] == 'o':
      if l[i] == 1:
        l[i + 1] = l[i - 1]
      else:
        l[i + 1] = not l[i - 1]
    else:
      if l[i] == 1:
        l[i + 1] = not l[i - 1]
      else:
        l[i + 1] = l[i - 1]
  
  if s[-1] == 'o':
    if l[-1] == 1:
      flag = l[0] == l[-2]
    else:
      flag = l[0] != l[-2]
  else:
    if l[-1] == 1:
      flag = l[0] != l[-2]
    else:
      flag = l[0] == l[-2]
  if flag:
    if s[0] == 'o':
      if l[0] == 1:
        flag = l[-1] == l[1]
      else:
        flag = l[-1] != l[1]
    else:
      if l[0] == 1:
        flag = l[-1] != l[1]
      else:
        flag = l[-1] == l[1]

  if flag:
    s = ''.join(['S' if i == 1 else 'W' for i in l])
    print(s)
    exit()

print(-1)