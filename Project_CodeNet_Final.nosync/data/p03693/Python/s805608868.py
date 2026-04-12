a,b,c=map(int,input().split())

s=int(str(a)+str(b)+str(c))

if s%4==0:
    print("YES")
else:
    print("NO")
