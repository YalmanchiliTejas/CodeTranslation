a=int(input())
b=3
c="";
for num in range(3):
    if(a==b):
        c="YES"
        break
    if(a!=b):
         c="NO"
    b+=2
print(c)