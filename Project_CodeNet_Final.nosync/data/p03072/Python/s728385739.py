#!/usr/bin/env python
# coding: utf-8

# In[19]:


import numpy as np


# In[49]:


N = int(input())
H = list(map(int, input().split()))
H = np.array(H)


# In[50]:


count = 1

for i in range(1,N):
    #print(i)
    if np.all(H[i] >= H[:i]):
        count += 1

print(count)


# In[ ]:




