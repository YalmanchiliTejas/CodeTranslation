r,g,y = map(int,input().split())
kazu = 100*r + 10*g + y
kazu_1 = 10*g + y
if kazu_1 % 4 ==0:
  print("YES")
else:
  print("NO")