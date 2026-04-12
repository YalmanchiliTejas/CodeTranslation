def culc(num_referee):
    data=[]
    for i in range(num_referee):
        data.append(int(input()))
    data.sort()
    sum_data=0
    data[0]=0
    data[len(data)-1]=0
    #print(data)
    for j in data:
        sum_data=sum_data+j
    avg=sum_data/(len(data)-2)
    print(int(avg))


num_referee=1
while(1):
    num_referee=input()
    #print(num_referee)
    if num_referee != "0":
        culc(int(num_referee))
    else:
        break

