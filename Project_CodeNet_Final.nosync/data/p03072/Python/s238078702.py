N = int(input())
H = list(map(int,input().split()))

cnt = 1
maximum = H[0]
for i in range(1,N):
    if H[i] >= maximum:
        cnt += 1
        maximum = H[i]
print(cnt)