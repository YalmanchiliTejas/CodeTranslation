n,x = map(int,input().split())
l = [[1,1],[5,3]]

for i in range(2,n):
    a = l[-1][0]
    b = l[-1][1]
    l.append([a*2+3,b*2+1])

ans = 0
for i in range(n-1,0,-1):
    if x >= l[i][0]+2:
        ans += l[i][1]+1
        x -= l[i][0]+2
    else:
        x -= 1

if x > 0:
    b = [0,1,1,1,0]
    ans += b[:x].count(1)
print(ans)