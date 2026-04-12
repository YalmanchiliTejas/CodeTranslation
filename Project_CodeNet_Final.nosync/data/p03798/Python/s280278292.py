import sys


def solve():
    input = sys.stdin.readline
    mod = 10 ** 9 + 7
    n = int(input().rstrip('\n'))
    s = [True if s == "o" else False for s in list(str(input().rstrip('\n')))]
    ls = [[0] * n for _ in range(4)]
    ls[0][0] = False
    ls[0][1] = False
    ls[1][0] = False
    ls[1][1] = True
    ls[2][0] = True
    ls[2][1] = False
    ls[3][0] = True
    ls[3][1] = True
    for i in range(1, n-1):
        ls[0][i+1] = (s[i] == ls[0][i]) == ls[0][i-1]
        ls[1][i+1] = (s[i] == ls[1][i]) == ls[1][i-1]
        ls[2][i+1] = (s[i] == ls[2][i]) == ls[2][i-1]
        ls[3][i+1] = (s[i] == ls[3][i]) == ls[3][i-1]
    for i in range(4):
        if (s[-1] == ls[i][-1] and ls[i][0] == ls[i][-2]) or (s[-1] != ls[i][-1] and ls[i][0] != ls[i][-2]):
            if (s[0] == ls[i][0] and ls[i][1] == ls[i][-1]) or (s[0] != ls[i][0] and ls[i][1] != ls[i][-1]):
                print("".join(["S" if ls[i][j] else "W" for j in range(n)]))
                exit()
    print(-1)


if __name__ == '__main__':
    solve()
