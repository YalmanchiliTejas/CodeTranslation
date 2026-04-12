def getinputdata():

    # 配列初期化
    array_result = []    
    data = input()
    array_result.append(data.split(" "))

    flg = True

    try:
        while flg:

            data = input()

            array_temp = []

            if(data != ""):
                
                array_result.append(data.split(" "))

                flg = True

            else:

                flg = False
    finally:

        return array_result

arr_data = getinputdata()

#apizza
a = int(arr_data[0][0])
#bpizza
b = int(arr_data[0][1])
#abpizza
c = int(arr_data[0][2])

#apizzaの枚数
x = int(arr_data[0][3])

#bpizzaの枚数
y = int(arr_data[0][4])

mysum1 = a * x + b * y
mysum2 = c * max(x, y) * 2
mysum3 = c * min(x, y) * 2 + a * (x-min(x, y)) + b * (y-min(x, y))

arr=[mysum1,mysum2,mysum3]
arr.sort()
print(arr[0])