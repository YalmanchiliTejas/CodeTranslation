H, W = map(int, input().split())

HW_list = []
for i in range(H):
    x = input()
    char_list = list(x)
    if "#" in char_list:
        HW_list.append(char_list)
    else:
        pass

i = 0
while True:
    count = 0
    for j in range(len(HW_list)):
        if HW_list[j][i] == ".":
            count += 1
        
    if count == len(HW_list):
        for j in range(len(HW_list)):
            del HW_list[j][i]

    else:
        i += 1
    if i > len(HW_list[0]) - 1:
        break
    
for j in range(len(HW_list)):
    print("".join(HW_list[j]))