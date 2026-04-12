from scipy import misc

N = int(input())
K = int(input())
d = len(str(N))
first = int(str(N)[0])
if K == 1:
    print(9*(d-1)+first)
elif K == 2:
    if d == 1:
        print('0')
    else:
        for i in range(1,d):
            if str(N)[i] != '0':
                second_dig = i+1
                second_num = int(str(N)[i])
                break
        else:
            second_dig = d
            second_num = 0
        print(((d-1)*(d-2)//2*81)+(first-1)*(d-1)*9+(d-second_dig)*9+second_num)
else:
    if K < 3:
        print('0')
    else:
        found_second = False
        found_third = False
        for i in range(1,d):
            if str(N)[i] != '0':
                if found_second == False:
                    second_dig = i+1
                    second_num = int(str(N)[i])
                    found_second = True
                else:
                    third_dig = i+1
                    third_num = int(str(N)[i])
                    found_third = True
                    break
        if found_second == False:
            print((d-1)*(d-2)*(d-3)//6*729+(first-1)*((d-1)*(d-2)//2*81))
        elif found_third == False:
            print((d-1)*(d-2)*(d-3)//6*729+(first-1)*((d-1)*(d-2)//2*81)+(second_num-1)*(d-second_dig)*9+(d-second_dig)*(d-second_dig-1)//2*81)
        else:
            print((d-1)*(d-2)*(d-3)//6*729+(first-1)*((d-1)*(d-2)//2*81)+(second_num-1)*(d-second_dig)*9+(d-second_dig)*(d-second_dig-1)//2*81+(d-third_dig)*9+third_num)