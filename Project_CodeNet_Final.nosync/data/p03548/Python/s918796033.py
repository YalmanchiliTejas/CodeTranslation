x,y,z=map(int,input().split())
ans=0
p=0
while p<=x:
    ans+=1
    p=(ans+1)*z+ans*y

print(ans-1)




