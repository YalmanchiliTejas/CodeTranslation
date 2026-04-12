def dict_set(dict_A, dict_B):
    '''
    A, Bのどちらにも存在するkeyに対して、小さい方のvalueをもつような辞書を作る。
    
    Parameters
    -------------------------------------------
    dict_A, dict_B, dictionary
    
    Returns
    -------------------------------------------
    dict_AandB
    
    '''
    dict_AandB = {}
    
    for key in dict_A:
        if key in dict_B:
            dict_AandB[key] = min(dict_A[key], dict_B[key])
            
    return dict_AandB
  
import collections

n = int(input())

# initialize
input_str = input()
input_list = []
count_dict = {}
   
for char in input_str:
    input_list.append(char)
    
count_dict = collections.Counter(input_list)

for i in range(1, n):
    input_str = input()
    input_list = []
    
    for char in input_str:
        input_list.append(char)
    
    count_dict = dict_set(count_dict, collections.Counter(input_list))
    
# print(count_dict)

prepare_list = []
for i, v in count_dict.items():
    for _ in range(v):
        prepare_list.append(i)

answer_list = sorted(prepare_list)
print(''.join(answer_list))