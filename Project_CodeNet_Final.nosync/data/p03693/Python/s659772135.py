a,b,c=[int(i) for i in input().split()]
num=100*a+10*b+c

if num%4==0:
    print("YES")
else:
    print("NO")