n,x=map(int,input().split())

patty = [2**(i+1)-1 for i in range(n+1)][::-1]
length = [2**(i+2)-3 for i in range(n+1)][::-1]

ans=0
end=[0,1,2,3,3]

for i in range(n):
    hambergar=[1,1+length[i+1],2+length[i+1],2+2*length[i+1],3+2*length[i+1]]
    if i==n-1:
        ans+=end[x-1]
    else:
        if hambergar[0]<x and x<hambergar[2]:
            x-=1
        
        elif hambergar[2]<x and x<hambergar[4]:
            ans+=patty[i+1]+1
            x-=hambergar[2]
        
        elif hambergar[2]==x:
            ans+=patty[i+1]+1
            break

        elif hambergar[4]==x:
            ans+=patty[i]
            break
        
        elif hambergar[4]<x or x<=1:
            break

print(ans)