# -*- coding: utf-8 -*-

def main(n, S):
    ans = ""
    S_list = sorted((set(S[0])))
    for s in S_list:
        cnt = float("INF")
        for i in range(n):
            cnt = min(cnt, S[i].count(s))
        ans = ans + s * cnt
    print(ans)
if __name__ == '__main__':
    n = int(input())
    S = []
    for i in range(n):
        S.append(input())
    
    main(n, S)