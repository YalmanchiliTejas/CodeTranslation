N = int(input())
H = list(map(int, input().split()))

max=0
cnt=0
for i in range(N):
    if H[i]>=max:
        cnt+=1
        max=H[i]
print(cnt)