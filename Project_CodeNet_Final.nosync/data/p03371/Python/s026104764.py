A,B,C,X,Y=map(int,input().split())
if A+B<C*2:
    print(A*X+B*Y)
else:
    if X>=Y:
        kazu=Y*C*2
        if A>=C*2:
            number=(X-Y)*C*2
            print(kazu+number)
        else:
            number=(X-Y)*A
            print(kazu + number)
    else:
        kazu=X*C*2
        if B>=C*2:
            number = (Y-X) * C*2
            print(kazu + number)
        else:
            number = (Y-X) * B
            print(kazu + number)
            