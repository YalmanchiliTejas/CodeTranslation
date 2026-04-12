a,b,c,x,y = map(int,input().split())

ans = 10**9
for i in range(max(x,y)+1):
    cnt = 2*c*i
    if x > i:
        cnt += a*(x-i)
    if y >i:
        cnt += b*(y-i)
    ans = min(ans,cnt)

print(ans)