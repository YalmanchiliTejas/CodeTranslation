mod = 10**9+7
n = int(input())
input_list = list(map(int,input().split()))
input_len = len(input_list)
remain_num = sum(input_list[1:])
remain_list = [remain_num]
for i in range(1,input_len):
    remain_list.append(remain_list[i-1]-input_list[i])

temp = 0
for i in range(input_len):
    temp = (temp+input_list[i]*remain_list[i])%mod
print(temp)