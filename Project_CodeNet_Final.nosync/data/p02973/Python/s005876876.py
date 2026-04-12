import bisect
from collections import deque
def LIS(a):
    lis = deque()
    lis.append(-1)
    for i in range(len(a)):
        index = bisect.bisect_left(lis,a[i])
        if index == 0:
            lis.appendleft(a[i])
        else:
            lis[index-1] = a[i]
    return len(lis)

def main():
    n = int(input())
    a = [int(input()) for _ in range(n)]
    print(LIS(a))

if __name__ == "__main__":
    main()