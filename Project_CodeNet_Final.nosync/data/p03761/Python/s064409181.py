import collections
n = int(input())
S=['0']*n
sum_key = []
counters = [0]*n
for i in range(n):
    S[i] = input()
for i in range(n):
    c = collections.Counter(S[i])
    li = list(c.keys())
    counters[i] = c
    sum_key += li
sum_key = set(sum_key)
#ord(a)=97
al = [chr(ord('a') + i) for i in range(26)]
dp = [100]*26
for i in range(n):
    ca = counters[i]
    for s in sum_key:
        dp[ord(s)-97] = min(dp[ord(s)-97],ca[s])
lia = []
for i in range(26):
    if dp[i]==0 or dp[i]==100:
        continue
    k = [al[i]]*dp[i]
    lia += k
lia.sort()
print(''.join(lia))