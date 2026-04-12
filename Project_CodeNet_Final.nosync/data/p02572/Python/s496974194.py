def main():
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    m = 10 ** 9 + 7
    tmp_sum = 0
    for i in range(n - 1):
        tmp_sum += a[i]
        tmp_sum %= m
        ans += tmp_sum * a[i+1]
        ans %= m
    
    print(ans)


if __name__ == '__main__':
    main()
