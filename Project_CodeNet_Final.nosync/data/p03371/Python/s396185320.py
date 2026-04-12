#!/usr/bin/env python
# coding: utf-8

# In[8]:


A,B,C,X,Y = map(int, input().split())


# In[10]:


ans1 = A*X + B*Y
ans2 = C*min(X,Y)*2 + A*(X-min(X,Y)) + B*(Y-min(X,Y))
ans3 = C*max(X,Y)*2
print(min(ans1, ans2, ans3))


# In[ ]:




