A,B,c,X,Y = map(int,input().split())
ans = 0

if X >= Y:
    x=X ; y=Y ; a=A ; b=B
else:
    x=Y ; y=X ; a=B ; b=A
    
if 2*c < a+b:
    ans += 2*c*y
    if x!=y:
        if 2*c < a:
            ans += 2*c*(x-y)
        else:
            ans += a*(x-y)
else:
    ans += a*x + b*y
    
print(ans)