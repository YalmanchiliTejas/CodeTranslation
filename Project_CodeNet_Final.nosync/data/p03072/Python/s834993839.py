n = int(input())
h = list(map(int,input().split()))

hmax_rui = [0]*n
hmax_rui[0] = h[0]
for i in range(1,n):
    hmax_rui[i] = max(hmax_rui[i-1],h[i])

cnt = 0
for i in range(n):
    if h[i]==hmax_rui[i]:
        cnt +=1
print(cnt)
