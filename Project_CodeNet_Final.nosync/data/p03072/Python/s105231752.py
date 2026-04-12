mt = int(input())
mt_list = list(map(int, input().split()))

j = 0
count = 0

for i in range(mt):

    visible_flg = True

    j = i

    while j > 0:
        if mt_list[i] < mt_list[j-1]:
            visible_flg = False
            break
        j -= 1
    
    if visible_flg:
        count += 1

print(count)