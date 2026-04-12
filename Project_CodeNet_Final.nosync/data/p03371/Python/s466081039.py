def calc(s, l, c, x, y):
    pat1 = s*x + l*y
    pat2 = 2*c*y
    pat3 = 2*c*x + l*(y-x)
    return min(pat1,pat2,pat3)

A,B,C,X,Y = map(int, input().split())
if X < Y:
    print(calc(A,B,C,X,Y))
else:
    print(calc(B,A,C,Y,X))