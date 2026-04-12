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

k = int(arr_data[0][0])
a = int(arr_data[0][1])
b = int(arr_data[0][2])

cnt = a - b

rate = a

if rate >= k:
    
    print(1)
    
elif cnt==0:

    print(-1)
else:
    
    if (k-rate) % cnt == 0:
        
        num = (k-rate) // cnt 
        
        print(1+ num*2)
    
    else:
        
        num = ((k-rate) // cnt) + 1
        
        if num>=1 :
        
            print(num*2+1)
        
        else:
            
            print(-1)
