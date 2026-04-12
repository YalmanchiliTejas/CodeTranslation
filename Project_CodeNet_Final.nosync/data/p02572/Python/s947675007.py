def solve():
    n = int(input())
    A = list(map(int, input().split()))
    ans = sum(A)
    ans *= ans
    ans -= sum([a * a for a in A])
    ans //= 2
    ans %= 1000000007
    print(ans)


if __name__ == "__main__":
    solve()
