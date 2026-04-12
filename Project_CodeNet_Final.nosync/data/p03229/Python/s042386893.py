def main():
    N = int(input())
    A = [int(input()) for i in range(N)]
    A.sort()
    BIG, SMALL = -1, 0
    big_index = N-1
    small_index = 0

    left = A[big_index]
    left_sign = BIG
    right = A[big_index]
    right_sign = BIG
    big_index-=1
    result = 0
    for i in range(1, N):
        val1, val2 = 0, 0
        s = A[small_index]
        b = A[big_index]
        against1, against2 = 0, 0
        if left_sign == BIG:
            val1 = abs(left - s)
            against1 = SMALL
        else:
            val1 = abs(left - b)
            against1 = BIG
        if right_sign == BIG:
            val2 = abs(right - s)
            against2 = SMALL
        else:
            val2 = abs(right - b)
            against2 = BIG
        if val1 > val2:
            result += val1
            if against1 == BIG:
                left = b
                left_sign = against1
                # print(b)
                big_index -= 1
            else:
                left = s
                left_sign = against1
                # print(s)
                small_index += 1
        else:
            result += val2
            if against2 == BIG:
                right = b
                right_sign = against2
                # print(b)
                big_index -= 1
            else:
                right = s
                right_sign = against2
                # print(s)
                small_index += 1
    print(result)



if __name__ == "__main__":
    main()