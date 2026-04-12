import sys
input = sys.stdin.readline


def print_ans(X):
    """Test Case
    >>> print_ans(30)
    Yes
    >>> print_ans(25)
    No
    >>> print_ans(35)
    Yes
    >>> print_ans(-10)
    No
    """
    if X >= 30:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    X = int(input().rstrip())
    print_ans(X)
