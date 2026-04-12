def solve():
    S = input()
    print('YNeos'[S=='AAA' or S=='BBB'::2])

if __name__ == '__main__':
    solve()
