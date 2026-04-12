N = int(input())
S = [input() for _ in range(N)]

for i in range(N):
    S[i] = {c: S[i].count(c) for c in S[i]}
chars = {c for c in 'abcdefghijklmnopqrstuvwxyz'}
for s in S:
    chars &= set(s.keys())
ans = []
for c in chars:
    small = float('inf')
    for s in S:
        small = min(small, s[c])
    ans += [c] * small
ans.sort()
print(''.join(ans))
