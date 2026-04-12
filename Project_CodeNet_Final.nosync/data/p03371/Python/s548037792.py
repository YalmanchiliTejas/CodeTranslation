A,B,C,X,Y=map(int,input().split())
ABset = 2*C
gokei = A*X+B*Y
for i in range(0,max(X+1,Y+1)):
    ABdai = i*ABset
    Adai = A*(X-i)
    if X<i:
        Adai = 0
    Bdai = B*(Y-i)
    if Y<i:
        Bdai = 0
    gokei = min(gokei,ABdai+Adai+Bdai)
print(gokei)