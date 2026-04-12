try:
    while True:
        num_list = []
        num_di = {}
        
        #リストに数値を格納して１番大きい数を出力する
        for i in range(0,5):
            line = list(map(int,input().split()))
            num_list.append(sum(line))
            num_di[sum(line)] = 65 + i
        num_list.sort()
        print(chr(num_di[num_list[4]]) + " " + str(num_list[4]))

#EOFErrorを検知する
except EOFError:
    pass
