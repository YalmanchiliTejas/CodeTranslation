a,b,c,x,y = map(int, input().split())
ans = 10**12
for i in range(0, (max(x,y)*2)+1, 2):
    xr = max(x-(i//2), 0)
    yr = max(0, y-(i//2))

    if ans > (i*c)+(xr*a)+(yr*b):
        ans = (i*c)+(xr*a)+(yr*b)

print(ans)