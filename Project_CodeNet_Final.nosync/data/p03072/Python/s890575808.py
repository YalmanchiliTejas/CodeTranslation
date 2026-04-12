N=int(input())

H = list(map(int,input().split()))
maxH = 0
count = 0
for i in range(N):
    if H[i]>=maxH:
        count+=1
    maxH=max(maxH,H[i])
print(count)