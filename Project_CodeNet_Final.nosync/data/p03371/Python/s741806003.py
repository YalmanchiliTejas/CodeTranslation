a,b,c,x,y = map(int, input().split())
ans=10**10
for i in range(0,max(x,y)*2+1,2):
    sm=c*i
    if x-i/2>0:
        sm+=a*(x-i/2)
    if y-i/2>0:
        sm+=b*(y-i/2)
    ans=min(ans,sm)

print(int(ans))
