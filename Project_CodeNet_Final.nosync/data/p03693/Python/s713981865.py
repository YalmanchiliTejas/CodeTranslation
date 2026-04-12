a,b,c = map(str,input().split())
ans = a + b + c
if int(ans)%4 == 0:
  print("YES")
else:
  print("NO")