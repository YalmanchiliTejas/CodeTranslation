def resolve():
    A, B, C, X, Y = map(int, input().split())
    C *= 2
    AB = A+B
    ans = 0
    while X > 0 or Y > 0:
        min_cnt = min(X, Y)
        if X and Y:
            if min_cnt*C <= (A*min_cnt) + (B*min_cnt):
                ans += min_cnt*C
                X -= min_cnt
                Y -= min_cnt
            else:
                ans += (A*min_cnt) + (B*min_cnt)
                X -= min_cnt
                Y -= min_cnt
        else:
            if max(X, Y)*C <= (A*X) + (B*Y):
                ans += max(X, Y)*C
                X -= max(X, 0)
                Y -= max(Y, 0)
            else:
                ans += (A*X) + (B*Y)
                X -= max(X, 0)
                Y -= max(Y, 0)
    return print(ans)

if __name__ == "__main__":
    resolve()