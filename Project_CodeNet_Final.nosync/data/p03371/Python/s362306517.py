a, b, c, x, y = map(int, input().split())


if a + b <= c*2:
  buy = a*x + b*y
elif a + b > c*2:
  num = [x,y]
  num.sort()
  buy = c*2*num[0]
  num_rest = num[1] - num[0]
  if num[1] == x:
    if a <= c*2:
      buy += a*num_rest
    else:
      buy += c*2*num_rest
  elif num[1] == y:
    if b <= c*2:
      buy += b*num_rest
    else:
      buy += c*2*num_rest
      
print(buy)