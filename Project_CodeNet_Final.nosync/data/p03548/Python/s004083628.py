x,y,z=map(int,input().split())
ans=0
while(1):
    ans+=1
    if ans*y+(ans+1)*z>x:
        print(ans-1)
        exit()