def main():
    N = int(input())
    A = list(map(int, input().split()))
    all_sum = sum(A) ** 2
    st = 0
    for i in range(N):
        st += A[i] ** 2
    print(int(((all_sum - st)//2) % 1000000007))
main()
