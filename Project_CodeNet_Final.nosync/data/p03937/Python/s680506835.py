h,w=[int(i) for i in input().split()]
s=0
l=0
for i in range(h):
  sf=True
  lf=False
  a=list(input().strip())
  for j in range(w):
    if a[j]=="#" and sf==True:
      s=j
      sf=False
      if s!=l and i!=0:
        print("Impossible")
        exit()
    if a[j]=="#" and lf==True:
      print("Impossible")
      exit()
    if a[j]=="." and sf==False and lf==False:
      l=j-1
      lf=True
  if sf==True:
    print("Impossible")
    exit()
  if lf==False:
    l=w-1
else:
  print("Possible")