R,G,B=map(int,input().split())
ans=100*R+10*G+B
if ans%4==0:
  print("YES")
else:
  print("NO")