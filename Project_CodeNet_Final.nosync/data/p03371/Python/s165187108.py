a,b,c,x,y = map(int,input().split())
res = float('inf')
for numc in range(2*max(x, y)+1):
    numa = max(0, x - numc//2)
    numb = max(0, y - numc//2)
    res = min(res, a*numa + b*numb + c*numc)
print(res)