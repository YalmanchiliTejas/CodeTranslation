A,B,C,X,Y = map(int, input().split())
minAB = min(X,Y)
maxAB = max(X,Y) - minAB
ans = 0
# C2枚のほうがお得
if A + B > C * 2:
    ans = minAB * C * 2
else:
    ans = minAB * A + minAB * B

# X or Y の残りをCと比較して計算
if X > Y:
    # C2枚のほうがお得
    if A > C * 2:
        ans += maxAB * C * 2
    else:
        ans += maxAB * A
else:
    # C2枚のほうがお得
    if B > C * 2:
        ans += maxAB * C * 2
    else:
        ans += maxAB * B

print(ans)