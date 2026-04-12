if __name__ == '__main__':
    n = int(input())
    a = [int(i) for i in input().split()]
    mod = 10**9+7
    sumA = sum(a)
    sumB = 0
    count = 0

    for i in range(n-1):
        sumB+=a[i]
        count += ((sumA-sumB)*a[i])%mod
    print(count%mod)

