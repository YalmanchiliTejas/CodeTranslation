import sys
 
def main():
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))
 
    ans = 0
    H = A[0]
    for a in A:
        if a >= H:
            ans += 1
 
        H = max(H, a)
 
    return ans
 
 
if __name__ == '__main__':
    print(main())