A,B,C,X,Y = map(int,input().split())
INF = 10**18

res = INF
for AB in range(max(X,Y)*2+1):
    x = AB*C
    a = AB//2
    b = AB//2
    if a < X:
        x += (X-a)*A
    if b < Y:
        x += (Y-b)*B
    if res > x:
        res = x
print(res)