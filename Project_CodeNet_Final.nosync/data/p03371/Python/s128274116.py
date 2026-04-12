import itertools
A,B,C,X, Y = list(map(int,input().split(" ")))
C2 = C * 2
ans = 0

if A+ B > C2:
    c = min(X,Y)
    ans += min(X,Y) * C2
    X -= c
    Y -= c



if A > C2:
    if B < C2:
        b_maisu = max(0,Y-X)
        ans += (X *  C2) + b_maisu * B


    else:
        ans += (max(X,Y)*C2)

elif A < C2:
    if B < C2:
        ans += A*X + Y * B
    else:
        a_maisu = max(0,X-Y)
        ans += (Y *  C2) + a_maisu * A

print(ans)
