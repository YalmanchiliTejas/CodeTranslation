a=input().strip().split(" ")

b=[int(i) for i in a]

c=100*b[0]+10*b[1]+b[2]

if(c%4==0):
    print("YES")
else:
    print("NO")
