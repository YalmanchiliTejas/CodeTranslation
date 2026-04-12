s=input()

a=0
b=0

for i in s:
    if i=="A":
        a=a+1
    else:
        b=b+1

if a==0 or b==0:
    print("No")
else:
    print("Yes")
    
        