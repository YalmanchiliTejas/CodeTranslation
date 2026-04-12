a,b,c,x,y = map(int,input().split())

ans = float("inf")
ab_max = max(x*2, y*2) 
for ab in range(ab_max+1):
    a_buy = max(x - (ab // 2),0)
    b_buy = max(y - (ab // 2),0)
    tmp = a * a_buy + b * b_buy + ab * c
    if ans > tmp:
        ans = tmp

print(ans)
