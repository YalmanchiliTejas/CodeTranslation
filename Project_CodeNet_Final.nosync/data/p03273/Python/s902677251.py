import sys
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    H, W = map(int, input().split())
    A = [''] * H
    for i in range(H):
        A[i] = input()

    row = [False]*H
    col = [False]*W
    for i in range(H):
        for j in range(W):
            if A[i][j] == '#':
                row[i] = True
                col[j] = True

    for i in range(H):
        if row[i]:
            for j in range(W):
                if col[j]:
                    print(A[i][j], end='')
            print()



if __name__ == '__main__':
    main()