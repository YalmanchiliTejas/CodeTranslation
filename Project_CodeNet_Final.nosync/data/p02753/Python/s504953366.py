seq=input()
a=0
b=0
for i in range(3):
    if seq[i]=="A":
        a+=1
    else:
        b+=1
if a>=1 and b>=1:
    print("Yes")
else:
    print("No")