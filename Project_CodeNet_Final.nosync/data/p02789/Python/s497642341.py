import sys
input = sys.stdin.readline
def print_ans(N, M):
    """Test Case
    >>> print_ans(3, 3)
    Yes
    >>> print_ans(3, 2)
    No
    """
    if N > M:
        print("No")
    else:
        print("Yes")


if __name__ == '__main__':
    N, M = map(int, input().rstrip().split())
    print_ans(N, M)


