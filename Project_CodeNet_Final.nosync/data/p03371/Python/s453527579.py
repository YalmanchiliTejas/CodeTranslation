#C
a,b,c,x,y=map(int,input().split())

#雰囲気
ans = a * x + b * y
cnt = 1
while x != 0 or  y!= 0:
    x = max(x - 1, 0)
    y = max(y - 1, 0)
    ans = min(ans,a*x+b*y+c * 2 * cnt)
    cnt += 1
    #print(ans,x,y)
print(ans)