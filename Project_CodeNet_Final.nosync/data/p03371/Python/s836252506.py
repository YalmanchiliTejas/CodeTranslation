a,b,c,x,y=map(int,input().split())
ans=712378627461242
for i in range(0,2*max(x,y)+1,2):
    mai=max(0,x-i//2)
    mbi=max(0,y-i//2)
    ans=min(ans,a*mai+b*mbi+c*i)
print(ans)