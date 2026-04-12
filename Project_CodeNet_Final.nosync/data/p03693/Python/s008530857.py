r,g,b =map(int,input().split())

C=r*100+g*10+b

if C%4==0:
    print("YES")

else:
    print("NO")