N, X = map(int, input().split())

# レベルLバーガーの厚さ, レベルLバーガーに含まれるパティの数
thick, patti = [1], [1]
for i in range(N):
    thick.append(2 * thick[-1] + 3)
    patti.append(2 * patti[-1] + 1)


def solve(n, x):
    if n == 0:
        return 0 + (x >= 1)

    # レベルL-1バーガー
    elif x <= 1 + thick[n - 1]:
        return solve(n - 1, x - 1)

    # 2つ目のレベルL-1バーガーにかかる
    else:
        return patti[n - 1] + 1 + solve(n - 1, x - 1 - thick[n - 1] - 1)


print(solve(N, X))
