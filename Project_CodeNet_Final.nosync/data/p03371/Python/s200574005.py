A, B, C, X, Y = map(int, input().split())


check = 0
ans = 0
if 2 * C < A + B:
    #ABピザを買ったほうが良いケース（同数までは）
    ans += min(X, Y) * 2 * C
    if 2 * C < A and X - Y > 0:
        #最後のAの枚数調整でもCを買ったほうが良い場合
        ans += (X - Y) * 2 * C
    elif X - Y > 0:
        check = 1
    if 2 * C < B and Y - X > 0:
        #最後のBの枚数調整でもCを買ったほうが良い場合
        ans += (Y - X) * 2 * C
    elif Y - X > 0:
        check = 2
    if check == 1:
        #最後の枚数調整でAだけ個別に買ったほうが良い場合
        ans += (X - Y) * A
    elif check == 2:
        #最後の枚数調整でBだけ個別に買ったほうが良い場合
        ans += (Y - X) * B
else:
    #どちらについても個別に買ったほうが安い場合
    ans = A * X + B * Y

print(ans)