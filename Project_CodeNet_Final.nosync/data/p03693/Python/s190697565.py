r,g,b=[x for x in input().rstrip().split()]

ans=int(r+g+b)
if ans%4==0:
    print("YES")
else:
    print("NO")
