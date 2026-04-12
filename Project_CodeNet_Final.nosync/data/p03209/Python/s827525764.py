import sys
input = sys.stdin.readline

def main():
    N, X = map(int, input().split())

    ALL = [0] * (N+1)
    PATE = [0] * (N+1)
    ALL[0] = 1
    PATE[0] = 1
    for i in range(1, N+1):
        ALL[i] = ALL[i-1] * 2 + 3
        PATE[i] = PATE[i-1] * 2 + 1
    
    def dfs(level, remain):
        if level == 0:
            return 1
        ans = 0
        # バン
        if remain > 0:
            remain -= 1
        # レベルL-1バーガー
        if remain > 0:
            if remain >= ALL[level - 1]:
                remain -= ALL[level - 1]
                ans += PATE[level - 1]
            else:
                ans += dfs(level - 1, remain)
                remain = 0
        # パティ
        if remain > 0:
            remain -= 1
            ans += 1
        # レベルL-1バーガー
        if remain > 0:
            if remain >= ALL[level - 1]:
                remain -= ALL[level - 1]
                ans += PATE[level - 1]
            else:
                ans += dfs(level - 1, remain)
                remain = 0
        # バン
        if remain > 0:
            remain -= 1
        return ans
    
    print(dfs(N, X))

if __name__ == "__main__":
    main()