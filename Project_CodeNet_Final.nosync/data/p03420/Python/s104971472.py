#!/usr/bin/env python
# coding: utf-8

# In[9]:


N,K = map(int, input().split())


# In[10]:


if K == 0:
    ans = N*N
else:
    ans = 0
    cnt = 1
    for b in range(K+1,N+1):
        mod = N%b
        x = N//b
        ans += x*cnt
        if mod >= K:
            ans += mod-K+1
        cnt += 1
print(ans)


# In[ ]:




