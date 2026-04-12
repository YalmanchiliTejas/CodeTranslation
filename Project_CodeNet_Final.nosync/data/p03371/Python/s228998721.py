def solve(A, B, C, X, Y):
    ret = float("inf")
    for a_num in range(X + 1):
        ab_num = 2 * (X - a_num)
        price = min(
            a_num * A + max(0, Y - ab_num // 2) * B + ab_num * C,
            a_num * A + max(ab_num, 2 * Y) * C
        )
        ret = min(ret,price)
    return ret

if __name__ == "__main__":
    A, B, C, X, Y = map(int, input().split())
    print(solve(A, B, C, X, Y))