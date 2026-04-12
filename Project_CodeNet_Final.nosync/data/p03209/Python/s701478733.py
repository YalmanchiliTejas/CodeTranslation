N, X = map(int, input().split())


Patti = [1]  # レベルLバーガーに含まれているパティの数
Size = [1]   # レベルLバーガーの大きさ
for i in range(50):
    Patti.append(Patti[-1] * 2 + 1)
    Size.append(Size[-1] * 2 + 3)


def solve(n, x):
    # 一番下のバンのみ（ただしレベル0バーガーはPになる）
    if x == 1:
        return 0 + (n == 0)

    # 一番下のバン + レベルL-1バーガーのどこかまで
    if 1 < x <= 1 + Size[n - 1]:
        return solve(n - 1, x - 1)

    # 一番下のバン + レベルL-1バーガー + 真ん中のパティまで
    if x == 1 + Size[n - 1] + 1:
        return Patti[n - 1] + 1

    # 一番下のバン + レベルL-1バーガー + 真ん中のパティ + レベルL-1バーガーの途中まで
    if 1 + Size[n - 1] + 1 < x < Size[n]:
        return 1 + Patti[n - 1] + solve(n - 1, x - (1 + Size[n - 1] + 1))

    # レベルLバーガーすべて
    if x == Size[n]:
        return Patti[n]


print(solve(N, X))
