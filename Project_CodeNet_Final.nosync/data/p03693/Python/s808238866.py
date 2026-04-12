rgb=input()
a=rgb.replace(" ", "")
b=int(a)
if b%4==0:
    print("YES")
else:
    print("NO")