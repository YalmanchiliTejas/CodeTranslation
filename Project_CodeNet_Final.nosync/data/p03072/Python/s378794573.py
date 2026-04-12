N = int(input())
H = list(map(int, input().split()))
cnt = 0
h = [H[0]]
for i in range(1, N):
    if max(h) <= H[i]:
        cnt += 1
    h.append(H[i])
print(cnt + 1)
