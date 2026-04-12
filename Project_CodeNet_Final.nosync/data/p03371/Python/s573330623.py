A,B,C,X,Y=map(int, input().split())

Ans=float('inf')

for i in range(0,10**5+1):
    price=2*C*i+A*max(0,X-i)+B*max(0,Y-i)
    if price<Ans:
        Ans=price

print(Ans)