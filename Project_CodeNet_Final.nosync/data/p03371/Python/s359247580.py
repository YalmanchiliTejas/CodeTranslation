a,b,c,x,y = [int(i) for i in input().split()]

ans = 0
dic = {x:a,y:b}

if a+b < 2*c:
    ans += a*x + b*y

else:
    n = dic[max(x,y)]
    k = min(x,y)
    
    ans += 2*c*k
    
    if n >= 2*c:
        ans += (max(x,y)-k)*2*c
        
    else:
        ans += (max(x,y)-k)*n

print(ans)