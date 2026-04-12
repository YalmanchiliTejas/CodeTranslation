N = int(input())
H = list(map(int, input().split()))

current = H[0]
cnt = 1
for i in range(1,N):
    if H[i]>=current:
        current = H[i]
        cnt+=1
print(cnt)