a,b,c,x,y=map(int, input().split())
c*=2
ans=10**9
for cc in range(max(x,y)+1):
    tmp = cc * c
    tmp += max(0, x-cc)*a
    tmp += max(0, y-cc)*b
    ans = min(ans, tmp)
print(ans)