a, b, c, x, y = map(int, input().split())
# ABピザ二枚がA,B一枚づつより高いなら普通に買えばいい
if a + b < c * 2:
    print(a * x + b * y)
else:
    # A,Bの多いほうに合わせてABを買う
    MAX = max(x, y)
    MIN = min(x, y)
    isXMAX = False
    if MAX == x:
        isXMAX = True
    AllAB = MAX * c * 2
    # A,Bの少ないほうに合わせて残りは普通に買う
    DivAB = MIN * c * 2
    if isXMAX:
        DivAB += (x - y) * a
    else:
        DivAB += (y - x) * b
    print(min(AllAB, DivAB))
