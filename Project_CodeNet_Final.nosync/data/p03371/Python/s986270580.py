a,b,c,x,y=map(int,input().split())

ans=10**10

for i in range(10**5+1):
    a_cnt=max(0,x-i)
    b_cnt=max(0,y-i)
    
    total=i*2*c+a_cnt*a+b_cnt*b
    ans=min(ans,total)

print(ans)