def seek(value):
    right = len(color_list) - 1
    left = 0
    while(True):
        mid = (right + left) // 2
        if(value > color_list[mid]):
            right = mid
        else:
            left = mid
        if(right - left <= 1):
            return right

N = int(input())    
color_list =  [int(input())]
for i in range(N-1):
    new_value = int(input())
    if(new_value > color_list[0]):
        color_list[0] = new_value
    elif(new_value <= color_list[-1]):
        color_list.append(new_value)
    else:
        new_index = seek(new_value)
        color_list[new_index] = new_value
print(len(color_list))