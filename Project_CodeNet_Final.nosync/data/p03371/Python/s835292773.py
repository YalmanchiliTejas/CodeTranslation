def main():
    A, B, C, X, Y = (int(i) for i in input().split())
    ans1 = A * X + B * Y
    ans2 = 0
    ans3 = 0
    if X < Y:
        ans2 += 2 * C * X
        ans2 += B * (Y-X)
        ans3 += 2 * C * Y
    else:
        ans2 += 2 * C * Y
        ans2 += A * (X-Y)
        ans3 += 2 * C * X

    print(min(ans1,ans2,ans3))

if __name__ == '__main__':
    main()