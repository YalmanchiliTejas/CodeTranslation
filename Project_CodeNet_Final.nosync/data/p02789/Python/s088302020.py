def solve():
    n, m = map(int, input().split())
    print('YNeos'[n!=m::2])

if __name__ == '__main__':
    solve()
