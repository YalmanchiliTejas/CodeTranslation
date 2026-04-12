A,B,C,X,Y=map(int,input().split())
minmoney=100000000000000000
money=0
for i in range(0,100001):
    money = 2*C*i+A*max(0,X-i)+B*max(0,Y-i)
    minmoney = min(minmoney,money)

print(minmoney)
