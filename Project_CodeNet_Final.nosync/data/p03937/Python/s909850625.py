h,w = map(int, input().split())
aaa = [input().replace('#','1').replace('.','0') for _ in range(h)]

ans = 'Impossible'
for i in range(h-1):
    # check up-down
    updown = bin(int(aaa[i],2) & int(aaa[i+1],2))
    if updown.count('1') >1:
        # print('updown')
        break
    # check left move
    # print(aaa[i+1], aaa[i+1].index('1') , aaa[i], aaa[i].rindex('1'))
    if aaa[i+1].index('1') < aaa[i].rindex('1'):
    # int(aaa[i+1]) > int(aaa[i]):
        # print('left')
        break
else:
    ans = 'Possible'
print(ans)

# for a in aaa:
#     print(a)