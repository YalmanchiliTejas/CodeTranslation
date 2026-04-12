def main():
    A, B, C, X, Y = map(int, input().split())
    if A >= 2*C and B >= 2*C:
        ans = max(X, Y) * 2 * C
        print(ans)
        return
    if A>= 2*C:
        num_c = X * 2
        ans = num_c * C
        if Y * 2 > num_c:
            ans += (Y - num_c//2) * B
        print(ans)
        return
    if B >= 2*C:
        num_c = Y * 2
        ans = num_c * C
        if X * 2 > num_c:
            ans += (X - num_c//2) * A
        print(ans)
        return
    if A + B >= 2*C:
        num_c = min(X, Y) * 2
        ans = num_c * C
        ans += (X - num_c//2) * A
        ans += (Y - num_c//2) * B
        print(ans)
        return
    ans = X * A + Y * B
    print(ans)

if __name__ == '__main__':
    main()
