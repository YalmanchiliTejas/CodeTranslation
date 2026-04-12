import sys
sys.setrecursionlimit(10**7)
def input(): return sys.stdin.readline().rstrip()


def main():
    _ = int(input())
    nums = tuple(map(int, input().split()))
    mod = 10 ** 9 + 7

    num_sum = sum(nums)
    part_sum = sum(map(lambda x: x**2, nums)) # naname

    print((num_sum**2 - part_sum) // 2 % mod)


if __name__ == '__main__':
    main()