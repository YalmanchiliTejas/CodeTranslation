#!/usr/bin/env python
# coding: utf-8

# In[6]:


import numpy as np


# In[33]:


H,W = map(int, input().split())
a = []
for _ in range(H):
    row = input()
    a.append([1 if row[i] == "#" else 0 for i in range(W)])


# In[36]:


a_array = np.array(a)
col_flag = True
row_flag = True
# print(a_array)
while col_flag:
    for col in range(len(a_array)):
        if sum(a_array[col]) == 0:
            a_array = np.delete(a_array, col, 0)
#             print(a_array)
            break
    else:
        col_flag = False
while row_flag:
    for row in range(len(a_array[0])):
        if sum(a_array[:,row]) == 0:
            a_array = np.delete(a_array, row, 1)
#             print(a_array)
            break
    else:
        row_flag = False
for i in range(len(a_array)):
    tmp = ["#" if x == 1 else "." for x in a_array[i]]
    print("".join(tmp))


# In[ ]:




