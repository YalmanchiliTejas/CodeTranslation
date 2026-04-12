#n=int(input())
a,b,c,x,y=map(int,input().split())
#l=list(map(int,input().split()))
#l=[list(map(int,input().split())) for i in range(n)]

ans=a*x+b*y

for i in range(1,max(x,y)+1):
    ans=min(ans,2*c*i+a*max(x-i,0)+b*max(y-i,0))
print(ans)
