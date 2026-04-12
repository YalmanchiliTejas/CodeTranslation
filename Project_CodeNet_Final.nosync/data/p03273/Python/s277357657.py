def getinputdata():

    array_result = []    
    array_result.append(input().split(" "))

    flg = True

    try:
        while flg:

            data = input()

            if(data != ""):
                
                array_result.append(data.split(" "))

                flg = True

            else:

                flg = False
    finally:

        return array_result

arr_data = getinputdata()

h = int(arr_data[0][0])
w = int(arr_data[0][1])

arr_temp01=[]
for i in range(1,1+h):
    
    if arr_data[i][0]!= w * ".":
        
        arr_temp01.append(arr_data[i][0]) 
    else:
        h-=1

arr_temp02=[]
for v in list(zip(*arr_temp01)):
    
    if "".join(v) != h*".":
    
        arr_temp02.append("".join(v))
    else:
        w-=1
        
for v in list(zip(*arr_temp02)):
    
    print("".join(v))