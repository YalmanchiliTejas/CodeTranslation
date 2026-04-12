import numpy as np

N = int(input())
n_list1 = list(map(int, input().split()))

n_list2 = list(n_list1)
n_list_test = list(n_list1)


n_list_max = np.max(n_list1)
n_list_min = np.min(n_list2)

n_list1.remove(n_list_max)
n_list2.remove(n_list_min)

# print(np.max(n_list))
# np.median(n_list - )
n_list1_median = int(np.median(n_list1))
n_list2_median = int(np.median(n_list2))

for x in n_list_test:
  if n_list1_median >= x:
    print(n_list2_median)
  else:
    print(n_list1_median)
 
    

