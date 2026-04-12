h, w = map(int, input().split())

area = []
for i in range(h):
    tmp = str(input())
    if tmp.find('#') == -1:
        #print('Not find')
        continue
    else:
        area.append(tmp)

#print(area)

area = list(zip(*area))

#print(area)

ans_list = []
for tmp in area:
    tmp = list(tmp)
    #print(tmp)
    if ('#' in tmp) == False:
        #print('Not find')
        continue
    else:
        ans_list.append(tmp)

ans_list = list(zip(*ans_list))

#print(ans_list)

for tmp in ans_list:
    ans = ''    
    for j in tmp:
        ans += j
    print(ans)


