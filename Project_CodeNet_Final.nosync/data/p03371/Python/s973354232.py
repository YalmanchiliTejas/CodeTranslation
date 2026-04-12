#n=int(input())
a,b,c,x,y=map(int,input().split())
#al=list(map(int,input().split()))
#l=[list(map(int,input().split())) for i in range(m)]
ans=a*x+b*y
for z in range(0,max(x,y)+1):
    ans=min(ans,2*z*c+max(x-z,0)*a+max(y-z,0)*b)

print(ans)


