def solve2():
    N = int(raw_input())
    s = [int(_) for _ in raw_input().split()]
    ans = 0
    pass_set = set()
    for C in range(1, N - 1):
        pass_set.clear()
        maxK = (N - 1) / C
        score = 0 # when k = 0: 0 -> (N - 1)
        for k in range(1, maxK+1):
            if N - 1 - k*C < C:
                break
            if (N-1-k*C) in pass_set or k*C in pass_set or (N-1-k*C) == k*C:
                break
            else:
                score += s[N-1-k*C] + s[k*C] # DP
                pass_set.add(N-1-k*C)
                pass_set.add(k*C)
            ans = max(ans, score)
    print ans

if __name__ == '__main__':
    solve2()
