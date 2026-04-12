a, b, ab, x, y = map(int, input().split())

na = 0
nb = 0
nab = 0

if a+b >= 2*ab:
  nab += 2*min(x, y)
  if x > y:
    if ab*2 >= a:
      na += x - int(nab/2)
    else:
      nab += 2*(x - int(nab/2))
  else:
    if ab*2 >= b:
      nb += y - int(nab/2)
    else:
      nab += 2*(y - int(nab/2))
else:
  na += x
  nb += y

print(na*a + nb*b + nab * ab)