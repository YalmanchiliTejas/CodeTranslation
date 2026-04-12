from bisect import bisect_left
from collections import deque

def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    ans = deque([A[0]])
    for i in range(1,N):
        index = bisect_left(ans,A[i])
        if index == 0:
            ans.appendleft(A[i])
        else:
            ans[index-1] = A[i]

    print(len(ans))



if __name__ == "__main__":
    main()