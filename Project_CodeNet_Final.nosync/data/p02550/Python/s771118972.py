def main():
    n, x, m = map(int, input().split())
    n_copy = n

    sum_a = x
    rem = [None] * m
    n -= 1
    rem[x] = (x, n)
    while n > 0:
        x = x * x % m
        sum_a += x
        n -= 1
        if rem[x] is None:
            rem[x] = (sum_a, n)
        else:
            unit = rem[x][1] - n
            unit_sum = sum_a - rem[x][0]
            ans = sum_a + (n // unit) * unit_sum
            n = n % unit
            while n > 0:
                x = x * x % m
                ans += x
                n -= 1
            print(ans)
            exit()


    print(sum_a)

main()