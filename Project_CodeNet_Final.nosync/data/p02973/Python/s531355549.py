def main():
    import sys
    import bisect
    import collections
    input = sys.stdin.readline
    N = int(input())
    A = [int(input()) for i in range(N)]
    tmp = collections.deque()
    for i in range(N):
        insert_index = bisect.bisect_left(tmp,A[i])
        if insert_index == 0:
            tmp.appendleft(A[i])
        else:
            tmp[insert_index-1] = A[i]
    answer = len(tmp)
    print(answer)

if __name__ == '__main__':
    main()