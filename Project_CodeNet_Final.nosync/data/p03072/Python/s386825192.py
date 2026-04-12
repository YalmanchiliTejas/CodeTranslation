
# coding: utf-8

# In[5]:

import sys
input = sys.stdin.readline
N = int(input())
A = list(map(int, input().split()))


# In[6]:

base = A[0]
counter = 1
for i in range(1, N):
    if A[i] >= base:
        counter += 1
        base = A[i]
print(counter)


# In[ ]:



