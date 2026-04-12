while True :
  a, b = map(int, input().split())
  if(a == b and b == 0) :
    break
  else :
    S = ["A", "B", "C", "D", "E"]
    shop = list()
    shop.append(a + b)
    for i in range(4) :
      a, b = map(int, input().split())
      shop.append(a + b)
    win = max(shop)
    Shop = shop.index(win)
    print(S[Shop], win)
  
  
