#B
N = int(input())
H = list(map(int,input().split()))
cnt = 1
for i in range(1,N):
    if max(H[0:i]) <= H[i]:
        cnt += 1
print(cnt)
