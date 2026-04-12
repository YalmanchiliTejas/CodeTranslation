N = int(input())
Hs = list(map(int,input().split()))

tmp_max = Hs[0]
cnt = 1
for n in range(1,N):
    if tmp_max<= Hs[n]:
        cnt += 1
        tmp_max = Hs[n]

print(cnt)