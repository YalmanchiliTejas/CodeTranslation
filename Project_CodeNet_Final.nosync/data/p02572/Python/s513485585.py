#!/usr/bin/env python
# coding: utf-8

# In[23]:


N = int(input())
A = list(map(int, input().split()))


# In[24]:


mod = 10**9+7
a_sum = sum(A)
a_sum_list = []
cnt = 0
for i,a in enumerate(A):
    a_sum_list += [a_sum-a-cnt]
    cnt += a
mylist = [a_sum_list[i]*a for i,a in enumerate(A)]
ans = sum(mylist)%mod
print(ans)


# In[ ]:




