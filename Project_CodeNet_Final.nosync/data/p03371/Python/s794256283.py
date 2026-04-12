a,b,c,x,y=map(int,input().split())
ans=a*x+b*y
for HaH in range(0,2*max(x,y)+1,2):
    ans = min(ans, c*HaH+max(0, a*(x-HaH//2))+max(0, b*(y-HaH//2)))
print(ans)