a,b,c,x,y=map(int,input().split())

ans=2000000000
for i in range(max(x,y)+1):
    total=i*2*c
    if i < x:
        total += (x-i)*a
        
    if i < y:
        total += (y-i)*b
    ans=min(ans,total)
print(ans)  