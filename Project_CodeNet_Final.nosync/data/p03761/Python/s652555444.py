n = int(input())
S = [input() for i in range(n)]
alp = [chr(i) for i in range(97, 97+26)]
cnt = [50] * 26
for s in S:
  for idx, a in enumerate(alp):
    tmp = s.count(a)
    cnt[idx] = min(cnt[idx], tmp)

ans = [si*cnt[ind] for ind, si in enumerate(alp)]
print(''.join(ans))