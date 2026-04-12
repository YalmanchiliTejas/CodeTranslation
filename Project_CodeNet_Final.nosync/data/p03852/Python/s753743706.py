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

s = arr_data[0][0]

if s=="a" or s=="i" or s=="u" or s=="e" or s=="o":
    
    print("vowel")

else:
    
    
    print("consonant")
