import sys
input = sys.stdin.readline


def main():
    H, W = map(int, input().split())
    A = [list(input()[:-1]) for _ in range(H)]

    B = [0]*H
    C = [0]*W
    for i in range(H):
        for j in range(W):
            if A[i][j]==".":
                B[i] += 1
                C[j] += 1
    
    ans = ""
    for i in range(H):
        if B[i]==W:
            continue
        for j in range(W):
            if C[j]==H:
                continue
            ans += A[i][j]
        ans += "\n"

    print(ans[:-1])

if __name__ == '__main__':
    main()