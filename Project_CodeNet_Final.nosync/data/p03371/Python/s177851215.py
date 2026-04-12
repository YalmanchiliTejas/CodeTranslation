A,B,C,x,y = map(int,input().split())
ans = 0
if A+B > 2*C:
    ans += min(x,y)*C*2
else:
    ans += x*A + y*B
    print(ans)
    exit()    

if x >= y:
    x -= y
    y = 0
    if A <2*C:
        ans += x*A
    else:
        ans += x*2*C    
else:
    y -= x
    x = 0
    if B < 2*C:
        ans += y*B
    else:
        ans += y*2*C
print(ans) 