S=input()
a=[]
b=[]
for i in range(3):
  if S[i]=="A":
    a+=[S[i]]
  else:
    b+=["B"]
if len(a)==3 or len(b)==3:
  print("No")
else:
  print("Yes")
