r,g,b=input().split()
s = r+g+b
ans = int(s)
if ans%4==0:
    print("YES")
else:
    print("NO")