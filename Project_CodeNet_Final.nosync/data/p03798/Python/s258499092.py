import sys
def input(): return sys.stdin.readline().strip()

def main():
    N = int(input())
    S = input()
    """
    0, 1番目を決定すればそこから先は一意に確定するのでO(4N)で愚直にチェック可能
    """
    ans = [0] * N
    for i in range(4):
        ans[0] = i % 2
        ans[1] = i // 2
        for j in range(1, N - 1):
            if S[j] == 'o' and ans[j] == 1:
                ans[j + 1] = ans[j - 1]
            elif S[j] == 'o' and ans[j] == 0:
                ans[j + 1] = 1 - ans[j - 1]
            elif S[j] == 'x' and ans[j] == 1:
                ans[j + 1] = 1 - ans[j - 1]
            else:
                ans[j + 1] = ans[j - 1]
        if S[-1] == 'o' and ans[-1] == 1 and ans[-2] != ans[0]: continue
        if S[-1] == 'o' and ans[-1] == 0 and ans[-2] == ans[0]: continue
        if S[-1] == 'x' and ans[-1] == 1 and ans[-2] == ans[0]: continue
        if S[-1] == 'x' and ans[-1] == 0 and ans[-2] != ans[0]: continue
        if S[0] == 'o' and ans[0] == 1 and ans[-1] != ans[1]: continue
        if S[0] == 'o' and ans[0] == 0 and ans[-1] == ans[1]: continue
        if S[0] == 'x' and ans[0] == 1 and ans[-1] == ans[1]: continue
        if S[0] == 'x' and ans[0] == 0 and ans[-1] != ans[1]: continue
        t = ''
        for a in ans: 
            if a == 0:
                t += 'W'
            else:
                t += 'S'
        print(t)
        return
    print(-1)

if __name__ == "__main__":
    main()
