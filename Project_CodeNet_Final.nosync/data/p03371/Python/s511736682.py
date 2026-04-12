a, b, c, x, y = map(int, input().split())
# print(a, b, c, x, y)

ans = 10000 * (10 **5) + 7
c_max = 0
if x > y:
  c_max = x * 2
else:
  c_max = y * 2

for cc in range(c_max+1):
  ac = x - (cc // 2)
  bc = y - (cc // 2)
  
  if ac < 0:
    ac = 0
  if bc < 0:
    bc = 0
  price = ac * a + bc * b + cc * c
  # print('price: {}, ac: {}, bc: {}, cc: {}'.format(price, ac, bc, cc))
  ans = min(ans, price)

print(ans)