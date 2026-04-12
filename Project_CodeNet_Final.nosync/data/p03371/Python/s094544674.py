a,b,c,x,y=map(int,input().split())
AB_sum=min(a+b,c*2)#AB1枚ずつの最小値
ans=0
ans+=min(x,y)*AB_sum
if x<y:
    if b<c*2:
        ans+=b*(y-x)
    else:
        ans+=(c*2)*(y-x)
else:
    if a<c*2:
        ans+=a*(x-y)
    else:
        ans+=(c*2)*(x-y)
print(ans)
