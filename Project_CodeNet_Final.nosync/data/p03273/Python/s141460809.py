arg1, arg2 = input().split()
#arg1 = '7'

input_list = []
for i in range(int(arg1)):
    input_list.append(input())

#input_list = ['......', '....#.', '.#....', '..#...', '..#...', '......', '.#..#.']
target_list = []
for row in input_list:
    target_list.append(list(row))
#print(target_list)


# 縦が難しい
# やっぱりまず横を消してしまう。
target_list2 = []
for i in range(len(target_list)):
    for j in range(len(target_list[i])):
        if target_list[i][j] == '#':
            target_list2.append(target_list[i])
            break

#print(target_list2)

target_list3 = list(map(list, zip(*target_list2)))

#print(target_list3)

target_list4 = []
for i in range(len(target_list3)):
    for j in range(len(target_list3[i])):
        if target_list3[i][j] == '#':
            target_list4.append(target_list3[i])
            break

#print(target_list4)

ans_list = list(map(list, zip(*target_list4)))
#print(ans_list)


for row in ans_list:
    moji = ''
    for x in row:
        moji += x
    print(moji)