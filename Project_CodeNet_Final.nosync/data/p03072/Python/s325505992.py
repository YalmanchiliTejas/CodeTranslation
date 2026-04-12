#山の数
N = int(input())

#山の高さデータ
H = [int(i) for i in input().split()] 
result = 0

for index, i in enumerate(H):
    if index - 1 < 0:
        result += 1 
    else:
        flag = 0
        for kindex in range(index):
            if H[kindex] > i:
                flag = 1     
        if flag == 0:
            result += 1
            

print(result)