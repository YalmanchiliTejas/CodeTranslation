from collections import deque
import bisect

def main():
    N = int(input())
    l = deque([])

    for i in range(N):
        a = int(input())
        if len(l) == 0 or a <= l[0]:
            l.appendleft(a)
        else:
            ind = bisect.bisect_left(l, a)
            l[ind-1] = a

    print(len(l))

if __name__ == "__main__":
    main()
