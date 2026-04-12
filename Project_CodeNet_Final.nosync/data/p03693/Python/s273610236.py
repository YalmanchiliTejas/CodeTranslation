a,b,c = list(map(int,input().strip().split()))

if (a *100 +b*10 +c) % 4 == 0:
  print("YES")
else:
  print("NO")