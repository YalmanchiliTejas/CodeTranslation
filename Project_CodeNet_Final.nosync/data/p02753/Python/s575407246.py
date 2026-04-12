S=input()
f=1
for i in range(1,3):
	if (S[i]!=S[0]):
	    f=0
if(f==0):
  print("Yes")
else:
  print("No")