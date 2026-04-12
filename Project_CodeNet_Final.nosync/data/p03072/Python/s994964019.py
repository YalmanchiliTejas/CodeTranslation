n = int(input())
HH = list(map(int, input().split()))
cnt = 0
for i,H in enumerate(HH):
    flg = True
    if i == 0:
        pass
    else:
        for H2 in HH[:i]:
            if H < H2:
                flg = False
                break
    
    if flg:
        cnt += 1

print(cnt)