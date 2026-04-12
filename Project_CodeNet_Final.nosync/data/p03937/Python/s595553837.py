#!/usr/bin/env python
# coding: utf-8

# In[21]:


H,W = map(int, input().split())
A = []
for _ in range(H):
    A.append(input())


# In[ ]:


cnt = 0
for i in range(H):
    for j in range(W):
        if A[i][j] == "#":
            cnt += 1
if cnt == H+W-1:
    print("Possible")
else:
    print("Impossible")

