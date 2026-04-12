
A,B,C,X,Y = map(int,input().split())


ans = X * A + Y * B

bul = True

while bul:

    bul = False

    if X > 0 and Y > 0 and A + B > 2*C:

        bul = True
        X -= 1
        Y -= 1

        ans = ans - (A+B) + 2*C

    elif X > 0 and A > 2*C:

        bul = True
        X -= 1

        ans = ans - A + 2*C

    elif Y > 0 and B > 2*C:

        bul = True
        Y -= 1

        ans = ans - B + 2*C

print (ans)
        
