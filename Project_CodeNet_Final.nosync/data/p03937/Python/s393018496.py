H,W=map(int,input().split())
P=sum([list(input()).count('#') for i in range(H)])
if P==H+W-1:
  print('Possible')
else:
  print('Impossible')