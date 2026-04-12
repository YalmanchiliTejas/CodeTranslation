r,g,b=input().split()
rgb=int(r+g+b)
if rgb%4==0:
    ans="YES"
else:
    ans="NO"
print(ans)