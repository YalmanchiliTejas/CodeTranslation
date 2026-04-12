a,b,c=map(str,input().split())
a+=b
a+=c
if int(a)%4==0:
    print("YES")
else:
    print("NO")