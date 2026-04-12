def resolve():
    import math
    a, b, c, x, y = map(int, input().split())
    ans = a*x + b*y
    #abの枚数だけ考える
    for i in range(1, max(x, y)+1):
        ab = i*2 #abピザを奇数個買うことはない
        total = ab*c + a*max(0, x-i) + b*max(0, y-i) #負の値を採らないようにmaxにしてる
        ans = min(ans, total)
    print(ans)
resolve()