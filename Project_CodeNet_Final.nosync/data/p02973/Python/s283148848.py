import sys
import bisect
from collections import deque

def main():
    _ = int(input())
    A = list(map(int, sys.stdin.readlines()))
    
    arr = deque()
    arr.append(A[0])
    for a in A[1:]:
        if a <= arr[0]:
            arr.appendleft(a)
        else:
            insert_index = bisect.bisect_left(arr, a)
            update = max(0, insert_index-1)
            arr[update] = a
    print(len(arr))
    
if __name__=='__main__':
    main()