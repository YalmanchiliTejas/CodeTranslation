s = list(map(int, input().split()))
a, b, c, x, y = s[0], s[1], s[2], s[3], s[4]
pa = 0
pb = 0
res = 10**10
for i in range(0, 2*(x+y+1), 2):
 t = i*c+(x-min(x, i//2))*a+(y-min(y, i//2))*b
 if t<res:
  res = t

print(res)