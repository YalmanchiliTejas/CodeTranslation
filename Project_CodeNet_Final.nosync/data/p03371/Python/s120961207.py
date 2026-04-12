a,b,c,x,y = map(int,input().split())

amax = x*a
bmax = y*b

ans = amax+bmax

for _ in range(max(x,y)):
    if x <= 0:
        ans = min(ans-b+2*c,ans)

    elif y <= 0:
        ans = min(ans-a+2*c,ans)

    else:
        ans = min(ans-a-b+2*c,ans)
        
    x-=1
    y-=1
 #   print(x,y,ans)

print(ans)