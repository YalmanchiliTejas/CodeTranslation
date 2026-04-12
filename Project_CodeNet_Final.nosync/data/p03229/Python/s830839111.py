
def resolve():
    # 隣り合う要素の差を大きくするには、大きい数と小さい数が交互に現れればよい。
    # 数列をsortして両端から交互に要素を取り、並べていく
    # 並べ方のパターン
    # 大きい方から並べるか小さい方から並べるか
    # 最後に並べる数字を左端におくか右端におくか

    # 全パターン試す

    N = int(input())
    A = sorted([int(input()) for _ in range(N)])

    # 左から、大小大小大小に並べる(右に要素を付け足す)
    # 最後に余った要素をどっちの両端に追加するか試す
    res1 = 0
    left = 0
    right = N - 1
    i = 0
    while (right - left) > 1:
        res1 += abs(A[right] - A[left])
        if i % 2 == 0:
            right -= 1
        else:
            left += 1
        i += 1
    if N % 2 == 1:
        # res1 = max(左端、右端)
        res1 += max(abs(A[N - 1] - A[right]), abs(A[left] - A[right]))
    else:
        res1 += max(abs(A[N - 1] - A[left]), abs(A[right] - A[left]))

    # 右から、小大小大小に並べる(左に要素を付け足す)
    # 最後に余った要素をどっちの両端に追加するか試す
    res2 = 0
    left = 0
    right = N - 1
    i = 0
    while (right - left) > 1:
        res2 += abs(A[right] - A[left])
        if i % 2 == 0:
            left += 1
        else:
            right -= 1
        i += 1
    if N % 2 == 1:
        # res2 = max(右端,左端)
        res2 += max(abs(A[0] - A[left]), abs(A[left] - A[right]))
    else:
        res2 += max(abs(A[0] - A[right]), abs(A[right] - A[left]))

    ans = max(res1, res2)
    print(ans)


if __name__ == "__main__":
    resolve()
