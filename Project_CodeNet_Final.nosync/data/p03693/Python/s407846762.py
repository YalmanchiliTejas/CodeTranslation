r,g,b=map(str,input().split())
X=int(r+g+b)
ans = "YES" if X%4==0 else "NO"
print(ans)