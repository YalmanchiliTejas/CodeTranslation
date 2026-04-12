def main():
    A, B, C, X, Y = map(int, input().split())
    ans = min(X, Y) * min(A+B, 2*C) + max(X-Y, 0) * \
        min(A, 2*C) + max(Y-X, 0) * min(B, 2*C)
    print(ans)


if __name__ == "__main__":
    main()
