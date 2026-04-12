
def main():
    A, B, C, X, Y = map(int, input().split())
    M1 = A*X + B*Y
    M2 = C*2*min(X, Y) + (Y >= X) * (Y - X) * B + (X > Y) * (X - Y) * A
    M3 = C*2*max(X, Y)
    ans = min(M1, M2, M3)
    print(ans)


if __name__ == "__main__":
    main()
