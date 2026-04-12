#!/usr/bin/env python
# coding: utf-8

# In[4]:


N = int(input())
A = []
for _ in range(N):
    A += [int(input())]


# In[6]:


A.sort()
ans = 0
if N%2 == 0:
    ans = 2*(sum(A[N//2:]) - sum(A[:N//2])) + A[N//2 - 1] - A[N//2]
else:
    ans = 2*(sum(A[N//2 + 1:]) - sum(A[:N//2]))
    ans -= min(A[N//2 + 1] - A[N//2], A[N//2] - A[N//2 - 1])
print(ans)

