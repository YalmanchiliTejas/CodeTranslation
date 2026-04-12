def main():
    N = int(input())
    A = list(map(int, input().split()))
    all_val = sum(A)
    A = A[::-1]

    sum_val = 0
    for i in range(len(A)):
        all_val -= A[i]
        sum_val += all_val * A[i] % (10**9 + 7)
    return sum_val % (10**9 + 7)

if __name__ == '__main__':
    print(main())