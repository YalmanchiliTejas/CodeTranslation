n = int(input())
S = [list(input()) for i in range(n)]
al = "abcdefghijklmnopqrstuvwxyz"
ans = ""
for i in range(26):
    cnt = 100
    for j in range(n):
        cnt = min(cnt, S[j].count(al[i]))
        if cnt == 0:
            break
    ans += al[i]*cnt
print(ans) 