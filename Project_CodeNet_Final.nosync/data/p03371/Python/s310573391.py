A,B,C,X,Y = map(int,input().split())
ans = float('inf')
for i in range(10**5+1):
    prices = 2*C*i+max(0,X-i)*A+max(0,Y-i)*B
    if prices < ans:
        ans = prices
print(ans)