def resolve():
    import sys
    input = sys.stdin.readline

    n = input().rstrip()
    past_a = 0

    ans = 0
    for a in input().rstrip().split(" "):
        a = int(a)
        ans += a * past_a
        past_a += a

    x = 1000000007

    ans = ans % x

    print(ans)

if __name__ == "__main__":
    resolve()
