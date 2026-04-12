import sys
input = lambda: sys.stdin.readline().rstrip()
input_nums = lambda: list(map(int, input().split()))

def main():
    N = int(input())
    H = [0] + input_nums()
    maxh = H[0]
    cnt = 0
    for i in range(1, N+1):
        if maxh <= H[i]:
            maxh = H[i]
            cnt += 1
    print(cnt)

if __name__ == '__main__':
    main()
