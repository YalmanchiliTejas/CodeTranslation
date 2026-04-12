n = int(input())

colors = []

for i in range(n):
  a = int(input())
  if i == 0:
    colors.append(a)
    continue
  if colors[-1] >= a:
    colors.append(a)
  elif a > colors[0]:
    colors[0] = a
  else:
    l, r = 0, len(colors)
    while r-l > 1:
      k = (r+l)//2
      if a > colors[k]:
        r = k
      else:
        l = k
    if a > colors[l]:
      colors[l] = a
    else:
      colors[r] = a

print(len(colors))