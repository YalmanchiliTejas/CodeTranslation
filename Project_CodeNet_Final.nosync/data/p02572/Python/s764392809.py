if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    cumsum_a = [0] * len(a)
    cumsum_a[0] = a[0]
    for i in range(1, len(a)):
        cumsum_a[i] += cumsum_a[i-1] + a[i]

    sum_val = 0
    num = 10 ** 9 + 7
    for i in range(0, n - 1):
        sum_val += a[i] * (cumsum_a[-1] - cumsum_a[i])
        if sum_val > num:
            sum_val %= num
    print(sum_val)

