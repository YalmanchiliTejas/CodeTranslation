def c_sum_of_product_of_pairs(MOD=10**9 + 7):
    N = int(input())
    A = [int(i) for i in input().split()]

    cumsum = [0]
    for a in A:
        cumsum.append(cumsum[-1] + a)
    return sum([(cumsum[N] - cumsum[i + 1]) * A[i] for i in range(N)]) % MOD

print(c_sum_of_product_of_pairs())