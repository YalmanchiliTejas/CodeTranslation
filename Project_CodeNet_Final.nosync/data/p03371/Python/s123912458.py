A,B,C,X,Y = map(int,input().split())

if X<Y:
        t = X
        X = Y
        Y = t
        t = A
        A = B
        B = t

ans = A*X+B*Y
ans = min(ans,A*(X-Y)+C*2*Y)
ans = min(ans,C*2*X)

print(ans)