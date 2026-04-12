#abc177_C_6_retry_累積和を使用する
int_n = int(input())
list_tmp = list(map(int, input().split()))
 
int_sum = 0
int_divide = (10**9) + 7
int_sum_tmp = sum(list_tmp)

for i in range(0, len(list_tmp) - 1):
  int_sum_tmp = int_sum_tmp - list_tmp[i]
  int_sum = int_sum + (int_sum_tmp * list_tmp[i])
print(int_sum % int_divide)
#  for j in range(i + 1, len(list_tmp)):
#    if list_tmp[i] >= int_divide:
#      list_tmp_i = list_tmp[i]%int_divide
#    else:
#      list_tmp_i = list_tmp[i]
#      
#    if list_tmp[j] >= int_divide:
#      list_tmp_j = list_tmp[j]%int_divide
#    else:
#      list_tmp_j = list_tmp[j]    
#    
#    int_sum = int_sum + (list_tmp_i*list_tmp_j)
#    
#    if int_sum >= int_divide:
#      int_sum = int_sum%int_divide
#      
#print(int_sum)