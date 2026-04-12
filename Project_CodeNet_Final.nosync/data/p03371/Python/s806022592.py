A,B,C,X,Y=list(map(int,input().split()))

ret=10**10

for i in range(max(2*X,2*Y)+1):
    cx=X-i//2
    cy=Y-i//2

    price=max(0,cx)*A+max(0,cy)*B+i*C
    ret=min(ret,price)

print(ret)