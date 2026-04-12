def main():
    N=input()
    A=list(map(int, input().split()))

    mod_value = 10**9 + 7
    sum_ = 0
    b_sum = 0
    for i in range(len(A)-1):
        b_sum = b_sum + A[len(A)-i-1]
        sum_ = sum_ + (A[len(A)- i - 2]*b_sum) % mod_value
    print(sum_%mod_value)
main()