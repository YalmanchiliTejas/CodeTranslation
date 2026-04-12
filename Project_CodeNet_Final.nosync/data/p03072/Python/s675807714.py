N = int(input())
H = [int(h) for h in input().split() ]


cnt = 1
max_H = H[0]
for i in range(1,N):
    max_H = max(max_H, H[i-1])
    if max_H <= H[i]:
        cnt += 1

print(cnt)