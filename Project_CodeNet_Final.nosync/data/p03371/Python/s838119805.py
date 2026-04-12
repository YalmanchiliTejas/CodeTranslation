def main():

    A, B, C, X, Y = map(int, input().split())

    num_a = 0
    num_b = 0
    num_c = 0

    if A >= C*2:
        num_c += X*2
    if B >= C*2:
        num_c += max(Y*2 - num_c, 0)

    left_X = max(X-num_c/2, 0)
    left_Y = max(Y-num_c/2, 0)

    # print(num_c, left_X, left_Y)
    if A + B >= C*2:
        num_c += min(left_X, left_Y)*2

    num_a = max(X-num_c/2, 0)
    num_b = max(Y-num_c/2, 0)

    # print(num_a, num_b, num_c)

    print(int(A*num_a + B*num_b + C*num_c))


if __name__ == '__main__':
    main()