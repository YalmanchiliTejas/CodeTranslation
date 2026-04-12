import sys
# input = sys.stdin.readline
sys.setrecursionlimit(10 ** 9)
MOD = 10 ** 9 + 7


N = int(input())
lst = [50] * 26
for _ in range(N):
    S = list(input())
    tmp = [0] * 26
    for s in S:
        tmp[ord(s) - ord('a')] += 1
    for i in range(26):
        lst[i] = min(lst[i], tmp[i])

for i in range(26):
    if lst[i] > 0:
        s = chr(ord('a') + i) * lst[i]
        print (s, end = '')

print ()