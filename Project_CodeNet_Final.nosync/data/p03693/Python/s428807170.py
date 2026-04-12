r,g,b=[int(i) for i in input().split()]
num=r*100+g*10+b

if num%4==0:
    print("YES")
else:
    print("NO")
