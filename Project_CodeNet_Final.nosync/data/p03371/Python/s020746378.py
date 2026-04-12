A,B,C,X,Y = map(int, input().split())

res=0

if X>0 and Y>0:
        if A+B > 2*C: # must buy C pizza
                minxy = min(X,Y)
                res += 2 * C * minxy
                X -= minxy
                Y -= minxy

# here, X == 0 or Y == 0




if X > 0: # buy some A pizza
        if A > 2 * C: # buy 2X * AB pizza
                res += C * 2*X
                Y -= X
        else: # buy A pizza
                res += X * A

if Y > 0: # buy some B pizza
        if B > 2 * C:
                res += C*2*Y
        else:
                res+= Y * B

print(res)