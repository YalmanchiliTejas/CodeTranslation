a,b,c,x,y = map(int,input().split())
p = max(x,y)
q = min(x,y)
ans = 0
if a+b>=2*c:
    if p == x:
        ans += 2*c*q + min(a,2*c)*(p-q)
    else:
        ans += 2*c*q + min(b,2*c)*(p-q)
else:
    if p == x:
        ans += (a+b)*q + min(a,2*c)*(p-q)
    else:
        ans += (a+b)*q + min(b,2*c)*(p-q)
         
print(ans)
# print(a,b,c,x,y)