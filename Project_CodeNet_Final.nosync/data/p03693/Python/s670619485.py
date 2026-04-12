# A - RGB Cards
r,g,b=list(input().split())
n=int("".join([r,g,b]))
if n%4==0:
    print("YES")
else:
    print("NO")


