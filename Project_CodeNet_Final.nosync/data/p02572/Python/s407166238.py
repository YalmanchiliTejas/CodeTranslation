
def resolve():
    MOD = 10 ** 9 + 7
    N = int(input())
    A = list(map(int, input().split()))

    # 面積として見る: 縦*横
    square = sum(A) ** 2

    # 対角線
    diag = sum([a * a for a in A])

    ans = (square - diag) // 2
    print(ans % MOD)


if __name__ == "__main__":
    resolve()