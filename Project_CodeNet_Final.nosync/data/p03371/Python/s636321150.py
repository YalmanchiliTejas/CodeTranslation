A, B, C ,X, Y = map(int, input().split())

ans = 0
if A <= C and B <= C: #A, Bの値段がCよりも安い-->素直にA, Bのみを買う
    ans = A * X + B * Y
elif A > C and B > C: #Cの値段がA, Bのどちらよりも安い
    if X > Y: #Aの必要枚数のほうが多い
        zan = (X-Y) * A
    else: #Bの必要枚数のほうが多い
        zan = (Y-X) * B
    ans = min(X, Y) * 2 * C + min(zan, C * (max(X, Y)- min(X, Y)) * 2) #残り枚数をA or Bで買うか、余るのを覚悟してABを買うか
else:
    if X > Y: #Xのほうが枚数多い
        ans = A * X + B * Y #素直に買う
        kari = Y * 2 * C + A * (X-Y) #余らないようにできるだけCを買う
        ans = min(ans, kari)
        kari = X * 2 * C #余ってもいいからCを買う
        ans = min(ans, kari)
    else: #X <= Y
        ans = A * X + B * Y
        kari = X * 2 * C + B * (Y-X)
        ans = min(ans, kari)
        kari = Y * 2 * C
        ans = min(ans, kari)
print (ans)
