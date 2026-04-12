import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

in_n = lambda: int(readline())
in_nn = lambda: map(int, readline().split())
in_s = lambda: readline().rstrip().decode('utf-8')
in_nl = lambda: list(map(int, readline().split()))
in_nl2 = lambda H: [in_nl() for _ in range(H)]
in_map = lambda: [s == ord('.') for s in readline() if s != ord('\n')]
in_map2 = lambda H: [in_map() for _ in range(H)]
in_all = lambda: map(int, read().split())


def main():

    N, X, M = in_nn()

    num_set = set()
    num_set.add(X)

    nums = [0] * (10**6)
    nums[0] = X

    now = X
    roop = -1
    for i in range(1, N):
        now = (now**2) % M
        if now in num_set:
            start = nums.index(now)
            pre_sum = sum(nums[:start])
            roop = i - start
            roop_sum = sum(nums[start:])
            break
        else:
            nums[i] = now
            num_set.add(now)
    else:
        print(sum(nums))
        exit()

    ans = pre_sum
    N -= start
    ans += roop_sum * (N // roop)

    N -= roop * (N // roop)
    ans += sum(nums[start:start + N])

    print(ans)


if __name__ == '__main__':
    main()
