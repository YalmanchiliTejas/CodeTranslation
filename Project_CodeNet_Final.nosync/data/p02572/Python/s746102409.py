def main():
    n = int(input())
    a_list = list(map(int, input().split()))

    mod = 1000000007
    sum_left = sum(a_list[1:])
    answer = 0
    for i in range(n-1):
        answer += (a_list[i] * sum_left) % mod
        sum_left -= a_list[i+1]
    print(int(answer % mod))


if __name__ == '__main__':
    main()
