import sys
from collections import Counter
input = sys.stdin.readline

n = int(input())
s = []
memo = []
ans = ''
check = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
check_cnt = [50] * 26
for i in range(n):
    s.append(list(input().rstrip('\n')))
    s[i].sort()
    memo.append(list(Counter(s[i]).items()))

for i in range(n):
    for check_m in range(26):
        flg = False
        for j in range(len(memo[i])):
            if check[check_m] == memo[i][j][0]:
                if check_cnt[check_m] > memo[i][j][1]:
                    check_cnt[check_m] = memo[i][j][1]
                flg = True
                break
        if flg:
            continue
        else:
            check_cnt[check_m] = 0

for i in range(26):
    for j in range(check_cnt[i]):
        ans += check[i]
print(ans)
