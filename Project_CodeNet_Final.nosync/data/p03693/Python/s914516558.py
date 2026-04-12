R, G, B=map(int,input().split())

if (100*R+10*G+B) % 4 == 0:
  print("YES")
  
else:
  print("NO")