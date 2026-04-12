def c_sum_of_product_of_pairs(MOD=10**9 + 7):
    N = int(input())
    A = [int(i) for i in input().split()]

    total = sum(A)
    cumsum = [0]
    for i in range(N):
        cumsum.append(cumsum[-1] + A[i])

    return sum([(total - cumsum[i]) * A[i - 1] for i in range(1, N)]) % MOD

print(c_sum_of_product_of_pairs())