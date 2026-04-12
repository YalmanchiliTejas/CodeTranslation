def solve():
    N = int(input())
    A = list(map(int, input().split()))

    sum_a = 0
    tmp = 0
    
    for i in range(N-1):
        tmp += A[i]
        sum_a += tmp * A[i+1]

  #  print(sum_a)

    ans = sum_a % 1000000007

    print(ans)


if __name__ == "__main__":
    solve()

