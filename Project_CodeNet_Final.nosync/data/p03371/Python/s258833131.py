a,b,c,x,y = map(int,input().split())
ans = 0
d = a+b
if d>2*c:
    while min(x,y)>0:
        ans += 2*c
        x -= 1
        y -= 1
else:
    while min(x,y)>0:
        ans += d
        x -= 1
        y -= 1
        

if x == 0:
    sus = min(2*c,b)
    while y>0:
        ans += sus
        y -= 1

        
else:
    sus = min(a,2*c)
    while x>0:
        ans += sus
        x -= 1
        
print(ans)
        