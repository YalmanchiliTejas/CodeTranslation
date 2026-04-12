import sys
from sys import stdin
def I():
    return stdin.readline().rstrip()
def MI():
    return map(int,stdin.readline().rstrip().split())
def LI():
    return list(map(int,stdin.readline().rstrip().split()))
#main part
n,x,m=MI()
stock=[]
for _ in range(1,n+1):
    if x not in stock:
        stock.append(x)
        x=(x**2)%m
        continue
    else:
        start=stock.index(x)
        repeat=stock[start:]
        l=len(repeat)
        n-=start
        sho=n//l
        amari=n%l
        s=sum(repeat)
        rest=0
        if amari!=0:
            for j in range(amari):
                rest+=repeat[j]
        print(s*sho+rest+sum(stock[:start]))
        sys.exit()
print(sum(stock))