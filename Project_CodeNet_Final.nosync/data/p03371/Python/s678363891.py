a,b,c,x,y = map(int,input().split())
ans = 100000000000000000000
for i in range(100001):
    ans = min(ans,i * 2 * c + max(0, x - i) * a + max(0, y - i) * b)
print(ans)