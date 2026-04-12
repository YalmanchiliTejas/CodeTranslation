import collections

n = int(input())
s = [sorted(input()) for i in range(n)]
s_ = [0 for i in range(n)]
alpha = 'abcdefghijklmnopqrstuvwxyz'
ans = []
for i in range(n):
    s_[i] = collections.Counter(s[i])
for i in alpha:
    tmp = 50
    for j in range(n):
        tmp = min(s_[j][i],tmp)
    if tmp > 0:
        ans.append(i*tmp)
print(''.join(map(str,ans)))