from sys import stdin
rs = lambda : stdin.readline().strip()
ri = lambda : int(rs())
ril = lambda : list(map(int, rs().split()))

def main():
    mod = 1000000007
    N = ri()
    A  = ril()
    x = sum(A) ** 2
    y = sum(list(map(lambda i : i * i, A)))
    ans = ((x - y) // 2) % mod
    print(ans)


if __name__ == '__main__':
    main()
