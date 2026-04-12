import sys
from bisect import bisect_right

input = sys.stdin.readline

def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    n = [A.pop(-1)]
    A.reverse()
    
    for a in A:
        if n[-1] <= a: n.append(a)
        else: n[bisect_right(n, a)] = a
    
    print(len(n))

if __name__ == '__main__':
    main()