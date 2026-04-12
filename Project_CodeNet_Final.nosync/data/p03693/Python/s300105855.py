r,g,b=input().split()
sum=100*r+10*g+b
if int(sum)%4==0:
    print("YES")
else:
    print("NO")