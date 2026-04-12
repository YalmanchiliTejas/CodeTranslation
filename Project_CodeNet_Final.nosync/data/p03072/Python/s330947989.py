N = int(input())
H = list(map(int, input().split()))

cnt = 1
for i in range(1, len(H)):
    h = H[i]
    h_ = H[:i]
    if h >= max(h_):
        cnt += 1

print(cnt)