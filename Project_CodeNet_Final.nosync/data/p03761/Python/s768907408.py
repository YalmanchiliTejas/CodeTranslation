import collections
n = int(input())
S = []
for i in range(n):
    s = collections.Counter(input())
    S.append(s)
ans = ''
for key in S[0].keys():
    cnt = S[0][key]
    for i in range(1,n):
        cnt = min(cnt,S[i][key])
    for i in range(cnt):
        ans += key
ans = sorted(ans)
print(''.join(ans))