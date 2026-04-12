def LI(): return list(map(int,input().split()))
A,B,C,X,Y = LI()
ans = float('INF')
for i in range(max(X,Y)+1):
    price = A*max(X-i,0)+B*max(Y-i,0)+C*2*i
    ans = min(ans,price)
print(ans)