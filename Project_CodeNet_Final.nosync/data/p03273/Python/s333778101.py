import sys
input = sys.stdin.readline


def main():
    H, W = map(int, input().split())
    A = [list(input()[:-1]) for _ in range(H)]

    B = [False]*H
    C = [False]*W
    for i in range(H):
        for j in range(W):
            if A[i][j]=="#":
                B[i] = True
                C[j] = True
    
    ans = ""
    for i in range(H):
        if B[i]==False:
            continue
        for j in range(W):
            if C[j]==False:
                continue
            ans += A[i][j]
        ans += "\n"

    print(ans[:-1])

if __name__ == '__main__':
    main()