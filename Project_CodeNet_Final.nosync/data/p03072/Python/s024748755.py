N = int(input())
H = list(map(int,input().split()))
note = H[0]
cnt = 1
for i in range(N-1):
    if note <= H[i+1]:
        cnt += 1
        note = H[i+1]
print(cnt)