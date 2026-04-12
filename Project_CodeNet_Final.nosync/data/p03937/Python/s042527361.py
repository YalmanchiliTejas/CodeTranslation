import sys
def main():
    input = sys.stdin.readline
    H, W = map(int, input().split())
    A = [list(input().rstrip()) for _ in range(H)]
    cnt = sum([1 if A[i][j]=='#' else 0 for i in range(H) for j in range(W)])

    ans = False
    stack = [(0, 0, 1)]
    while stack:
        i, j, d = stack.pop()
        if i == H-1 and j == W-1:
            if d == cnt:
                ans = True
            break
        for di, dj in [(0,1), (1,0)]:
            ni, nj = i+di, j+dj
            if ni >= H or nj >= W: continue
            if A[ni][nj] != '#': continue
            stack.append((ni, nj, d+1))
    print('Possible' if ans else 'Impossible')

if __name__ == '__main__':
    main()