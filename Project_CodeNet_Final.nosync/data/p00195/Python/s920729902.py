while True :
  a, p = map(int, input().split())
  if(a == 0 and p== 0) :
    break
  else :
    m = ["A", "B", "C", "D", "E"]
    shop = list()
    shop.append(a + p)
    for i in range(4) :
      a, p = map(int, input().split())
      shop.append(a + p)
    top = max(shop)
    Shop = shop.index(top)
    print(m[Shop], top)
