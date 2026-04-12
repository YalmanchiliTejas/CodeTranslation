n,x = map(int, input().split())

b = [[1,1]]

for i in range(n):
    b.append([b[-1][0]*2+3, b[-1][1]*2+1])

ans = 0
for i in range(len(b)):
    if x >= b[-1-i][0]:
        x -= b[-1-i][0]
        ans += b[-1-i][1]
        if x > 0:
            x-=1
            ans += 1
        if x>=b[-1-i][0]:
            x -= b[-1 - i][0]
            ans += b[-1 - i][1]
            break
    x-=1
    if x<=0:
        break

print(ans)
