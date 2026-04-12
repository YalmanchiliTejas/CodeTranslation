def main():
    N = int(input())
    A = [int(input()) for i in range(N)]
    A.sort()
    le, ri = A[-1], A[-1]
    # print(le, ri)
    from collections import deque
    A = deque(A[:N-1])
    ans = 0
    for i in range(N-1):
        cur = [abs(A[0] - le), abs(A[-1] - ri),
               abs(A[-1] - le), abs(A[0] - ri)]
        #print(le, ri, cur)
        if max(cur) == cur[0]:
            c = A.popleft()
            ans += abs(c - le)
            le = c
        elif max(cur) == cur[1]:
            c = A.pop()
            ans += abs(c - ri)
            ri = c
        elif max(cur) == cur[2]:
            c = A.pop()
            ans += abs(c - le)
            le = c
        else:
            c = A.popleft()
            ans += abs(c - ri)
            ri = c
    print(ans)


if __name__ == '__main__':
    main()
