n = int(input())
h = list(map(int, input().strip().split()))

flg = 0
cnt = 1

for i in range(1,len(h)):
    for j in range(0,i):
        if h[j]>h[i]:
            flg =1
    if flg == 0:
        cnt += 1
    else:
        flg = 0

print(cnt)