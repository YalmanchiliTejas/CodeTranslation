a=input("");
flag=False;
for i in range(0,len(a)-1):
  if a[i]=='A' and a[i+1]=='C':
    flag=True;
if flag==True:
  print("Yes");
else:
  print("No");