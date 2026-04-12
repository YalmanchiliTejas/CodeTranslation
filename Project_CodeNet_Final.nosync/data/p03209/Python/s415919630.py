n,x = [int(i) for i in input().split()]

def p(l, x):
  if x == 0:
    return 0
  if l == 1:
    if x == 1:
      return 0
    elif x == 2:
      return 1
    elif x == 3:
      return 2
    else:
      return 3
  else:
    w = 2**(l + 2) - 3
    if x == w:
      return 2**(l + 1) - 1
    hw = w // 2 + 1
    if x < hw:
      return p(l - 1, x - 1)
    elif x > hw:
      return 2**l + p(l - 1, x - hw)
    else:
      return 2**l
    
print(p(n, x))