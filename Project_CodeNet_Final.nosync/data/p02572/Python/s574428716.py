def main():
    N = int(input())
    A = list(map(int, input().split()))
    mod = 10 ** 9 + 7
    A_cum_sum = [A[-1]]
    for a in A[::-1][1:]:
        A_cum_sum.append(a + A_cum_sum[-1])
    A_cum_sum = A_cum_sum[::-1]
    ans = 0
    for i in range(N-1):
        sum_mod = A_cum_sum[i+1] % mod
        mul_mod = (A[i] * sum_mod) % mod
        ans = (ans + mul_mod) % mod
    print(ans)


if __name__ == '__main__':
    main()
