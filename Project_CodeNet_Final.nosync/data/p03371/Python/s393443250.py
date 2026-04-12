a,b,c,x,y = map(int,input().split())

ans = float("inf")

for i in range(3*10**5):
    tmp = 0
    tmp += c * i
    tmp += max(a * (x - i // 2), 0)
    tmp += max(b * (y - i // 2), 0)
    ans = min(ans, tmp)
print(ans)