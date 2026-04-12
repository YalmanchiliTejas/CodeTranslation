A,B,C,X,Y = map(int,input().split())

ans = A*X+B*Y
price = 0
AB = 2*C

for i in range(max(X,Y)+1):
    price = AB*i + max(0,X-i)*A + max(0,Y-i)*B
    ans = min(ans,price)

print(ans)