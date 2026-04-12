N = int(input())
S = str(input())
K = int(input())

hogo = list(S)
rewrite = list(S)

cnt = 0
for s in range(0, N):
    if rewrite[s] != (hogo[K - 1]):
        rewrite[cnt] = "*"
    cnt += 1

print(''.join(rewrite))