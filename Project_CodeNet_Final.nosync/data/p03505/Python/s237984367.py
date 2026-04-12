g,a,b=map(int,input().split())
if g<=a:
  print(1)
else:
  if a<=b:
    print(-1)
  else:
    if (g-a)%(a-b)==0:
      print(2*((g-a)//(a-b))+1)
    else:
      print(2*((g-a)//(a-b)+1)+1)