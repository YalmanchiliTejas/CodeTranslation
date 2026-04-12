N=raw_input()
hotel=map(int, raw_input().split())

cnt=0

for i,h in enumerate(hotel):
#    print i, h
    flg = 1
    for j in range(i+1):
#        print "--", h, hotel[j]
        if h < hotel[j]:
            flg = 0
            break

    if flg == 1:
        cnt += 1

print cnt
