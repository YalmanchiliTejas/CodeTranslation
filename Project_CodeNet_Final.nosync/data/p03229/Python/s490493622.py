
def resolve():
    # 隣り合う要素の差を大きくするには、大きい数と小さい数が交互に現れればよい。
    # 数列をsortして両端から交互に要素を取り、並べていく
    # 並べ方のパターン 小大小大小大を例に
    # |a1 -a2| + |a2 - a3| + |a3-an-1| + |an-1 - an|
    # 式を見ると両端は1回、その他は2回計算される

    def f(arr):
        res = 0
        for i in range(N - 1):
            res += abs(arr[i + 1] - arr[i])
        return res

    N = int(input())
    A = sorted([int(input()) for _ in range(N)])

    # Nが偶数なら、大小…大小
    # Nが奇数なら、大小…大小大 or 小大…小大小の二択の良い方

    mid = N // 2
    ans = 0
    if N % 2 == 0:
        low, high = A[:mid], A[mid:]
        B = []
        for i in range(mid):
            B.append(high[i])
            B.append(low[i])
        ans = f(B)

    else:
        res1 = 0
        low, high = A[:mid], A[mid + 1:]
        B = []
        for i in range(mid):
            B.append(high[i])
            B.append(low[i])
        # 後方に追加
        B.append(A[mid])
        res1 = f(B)

        # 先頭に追加
        B = [A[mid]] + B[:-1]

        ans = max(res1, f(B))

    print(ans)


if __name__ == "__main__":
    resolve()
