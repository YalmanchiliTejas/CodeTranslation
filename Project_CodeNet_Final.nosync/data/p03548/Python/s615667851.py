x,y,z=map(int,input().split())
cnt=0
l=0
while l<=x:
    l=0
    cnt+=1
    l+=(cnt*y)+(cnt+1)*z
else:
    print(cnt-1)