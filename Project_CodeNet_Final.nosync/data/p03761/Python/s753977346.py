import collections

n = int(input())
alp = [50] * 26

for i in range(n):
    S = collections.Counter(list(input()))
    for j in range(26):
        if chr(97 + j) in S.keys():
            alp[j] = min(alp[j], S[chr(97 + j)])
        else:
            alp[j] = 0
ans = []
for i in range(26):
    ans += [chr(97 + i)] * alp[i]
print(''.join(ans))