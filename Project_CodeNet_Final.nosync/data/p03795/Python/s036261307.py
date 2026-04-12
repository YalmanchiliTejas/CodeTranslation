#__author__ = "tatuo"
#__date__ = "$Mar 3, 2018 12:34:20 PM$"

import math
import re
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

n = int(arr_data[0][0])

print(n*800 - n//15*200)

#x = "ABC" if n <1200 else "ARC"
#
#print(x)

#s1 = arr_data[0][0][0]
#s2 = arr_data[1][0][1]
#s3 = arr_data[2][0][2]
#
#print(s1+s2+s3)
#
