N, X = map(int, input().split())

# レベルLバーガーの厚さ, レベルLバーガーに含まれるパティの数
thick, patti = [1], [1]
for i in range(N):
    thick.append(2 * thick[-1] + 3)
    patti.append(2 * patti[-1] + 1)


def solve(n, x):
    if x == 1:  # 一番下のバン(ただしレベル0バーガー参照時には+1)
        return 0 + (n == 0)

    # 一番下のバン + レベルL-1バーガーの途中まで
    elif 1 < x <= 1 + thick[n - 1]:
        return solve(n - 1, x - 1)

    # 一番下のバン + レベルL-1バーガー + 真ん中のパティ
    elif x == 2 + thick[n - 1]:
        return patti[n - 1] + 1

    # 一番下のバン + レベルL-1バーガー + 真ん中のパティ + レベルL-1バーガーの途中まで
    elif 2 + thick[n - 1] < x <= 2 * thick[n - 1] + 2:
        return patti[n - 1] + 1 + solve(n - 1, x - 1 - thick[n - 1] - 1)

    # 一番下のバン + レベルL-1バーガー + 真ん中のパティ + レベルL-1バーガー + 最後のバン
    elif x == 2 * thick[n - 1] + 3:
        return 2 * patti[n - 1] + 1


print(solve(N, X))
