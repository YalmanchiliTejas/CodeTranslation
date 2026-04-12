N, *H = map(int, open(0).read().split())
ma = [H[0]]
for hi in H[1:]:
    ma.append(max(hi, ma[-1]))
cnt = 1
for i in range(1, N):
    cnt += H[i] >= ma[i - 1]
print(cnt)