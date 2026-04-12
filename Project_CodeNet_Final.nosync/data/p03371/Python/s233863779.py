a,b,ab,x,y = map(int,input().split())

ans = a*x + b*y
ch = -a-b + 2*ab
for i in range(1,max(x,y)+1):
    if i <= min(x,y):
        ans = min(ans , ans + ch)
    else:
        if x < y:
            ans = min(ans , ans + ch + a)
        else:
            ans = min(ans , ans + ch + b)
print(ans)