import math
import sys

def getinputdata():

    # 配列初期化
    array_result = []
    
    data = input()

    
    array_result.append(data.split(" "))

    flg = 1

    try:


        while flg:

            data = input()

            array_temp = []

            if(data != ""):
                
                array_result.append(data.split(" "))

                flg = 1

            else:

                flg = 0
    finally:


        return array_result





arr_data = getinputdata()

r = arr_data[0][0]
g = arr_data[0][1]
b = arr_data[0][2]

print("YES" if int(r+g+b) % 4==0 else "NO")


