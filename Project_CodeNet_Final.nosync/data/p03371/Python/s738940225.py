a,b,c,x,y = map(int,input().split())
ans = 10**10
for i in range((x+y)+1):
    tmp = 2*c*i + a*(max(x-i,0)) + b*(max(y-i,0))
    ans = min(ans,tmp)
print(ans)