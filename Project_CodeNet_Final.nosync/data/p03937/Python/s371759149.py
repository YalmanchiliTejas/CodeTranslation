import sys
input = sys.stdin.readline
def main():
    H, W = map(int, input().split())
    A = [list(input().rstrip()) for i in range(H)]
    CNT = 0
    for i in range(H):
        for j in range(W):
            if A[i][j] == '#':
                CNT += 1
    if CNT == H+W-1:
        print('Possible')
    else:
        print('Impossible')

if __name__ == '__main__':
    main()