import sys

sys.setrecursionlimit(10 ** 6)

def find(idx, c, arr, tb):

    if c == 0:
        return 0

    if idx <= 0 or idx < 2 * c - 1:
        return float('-inf')

    if (idx, c) in tb:
        return tb[(idx, c)]

    rs = find(idx - 2, c - 1, arr, tb) + arr[idx - 1]
    rs = max(rs, find(idx - 1, c, arr, tb))

    tb[(idx, c)] = rs
    return rs

def main():

    n = int(input())
    arr = [int(e) for e in input().split(' ')]
    print(find(n, n // 2, arr, {}))
    return 0


main()
