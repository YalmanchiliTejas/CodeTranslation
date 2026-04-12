def md_burger(n, x):
  if x == 1:
    if n == 0:
      return 1
    else:
      return 0
  elif 1 < x < a[n-1]+2:
    return md_burger(n-1, x-1)
  elif x == a[n-1]+2:
    return p[n-1]+1
  elif a[n-1]+2 < x < 2*a[n-1]+3:
    return p[n-1]+1+md_burger(n-1, x-2-a[n-1])
  else:
    return 2*p[n-1]+1

if __name__=="__main__":
  n, x = input().split()
  a = [1]
  p = [1]
  for i in range(0, int(n)):
    a.append(a[i] * 2 + 3)
    p.append(p[i] * 2 + 1)
  print(md_burger(int(n), int(x)))