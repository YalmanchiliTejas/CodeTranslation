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

#椅子はば
x = int(arr_data[0][0])
y = int(arr_data[0][1])
z = int(arr_data[0][2])

#print(x, y, z)

hasi = y + z

naka = y + z 

#座れる人数初期値
cnt = 0

#はしに座れる人数
#cnt+=x//(hasi)
#print(cnt)


if x >= hasi * 2:
    
    cnt += 2
    #残り
    x -= hasi * 2
    
elif x >= hasi:
    
    cnt += 1
    #残り
    x -= hasi



x-=z
#中に座れる人数
cnt += x // naka

print(cnt)



