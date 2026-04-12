import sys
input = sys.stdin.readline
def print_ans(N, hs):
    """Test Case
    >>> print_ans(4, [6, 5, 6, 8])
    3
    >>> print_ans(5, [4, 5, 3, 5, 4])
    3
    >>> print_ans(5, [9, 5, 6, 8, 4])
    1
    """
    ans = 0
    tmp_max = 0
    for h in hs:
        if h >= tmp_max:
            ans +=1
        tmp_max = max(tmp_max, h)
    print(ans)

if __name__ == '__main__':
    N = int(input().rstrip())
    hs = list(map(int, input().rstrip().split()))
    print_ans(N, hs)
