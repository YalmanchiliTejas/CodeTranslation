while True :
    N = int(input())
    if N == 0 :
        break
    data = list(int(input()) for i in range(N))
    
    data.sort()
    del data[0]
    del data[-1]
    
    data_ave = sum(data)/len(data)
    print(int(data_ave))
