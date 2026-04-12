a,b,c,x,y = map(int,input().split())

ans=float("inf")
for i in range(0,max(x,y)*2+1,2):
    ans = min(ans, a*max(0,x-i/2)+b*max(0,y-i/2)+c*i)
print(int(ans))