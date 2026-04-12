# vim: set fileencoding=utf-8:
import collections


def main():
    # すべての数に対して、すべての数との差を計算する(10^5)か？TLEだ
    # 最大にするには、配列の中央の差が最大となるようにジグザグにしてけばいい
    N = input()
    A = sorted([input() for _ in xrange(N)])

    a = uzuamuki_sort(A, start="max", lr="right")
    b = uzuamuki_sort(A, start="max", lr="left")
    c = uzuamuki_sort(A, start="min", lr="right")
    d = uzuamuki_sort(A, start="min", lr="left")
    anss = [cal_ans(ele, N) for ele in [a, b, c, d]]
    print(max(anss))


def cal_ans(arr, N):
    ans = 0
    for i in xrange(N - 1):
        ans += abs(arr[i] - arr[i + 1])

    return ans


def uzuamuki_sort(A, start, lr):
    deq = collections.deque(A)
    uzu = collections.deque()

    def max_lr():
        uzu.appendleft(deq.popleft())
        uzu.append(deq.popleft())

    def max_rl():
        uzu.append(deq.popleft())
        uzu.appendleft(deq.popleft())

    def min_lr():
        uzu.appendleft(deq.pop())
        uzu.append(deq.pop())

    def min_rl():
        uzu.append(deq.pop())
        uzu.appendleft(deq.pop())

    if start == "max":
        uzu.append(deq.popleft())
        if lr == "right":
            while True:
                try:
                    min_rl()
                    max_rl()
                except IndexError:
                    break
        elif lr == "left":
            while True:
                try:
                    min_lr()
                    max_lr()
                except IndexError:
                    break

    elif start == "min":
        uzu.append(deq.pop())
        if lr == "right":
            while True:
                try:
                    max_rl()
                    min_rl()
                except IndexError:
                    break
        elif lr == "left":
            while True:
                try:
                    max_lr()
                    min_lr()
                except IndexError:
                    break

    return list(uzu)


if __name__ == "__main__":
    main()
