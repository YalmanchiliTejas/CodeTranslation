
# coding: utf-8

# In[103]:


n,x = map(int, input().split())


# In[104]:


def p(n):
    return 2 ** (n+1) - 1
def b(n):
    return 2 ** (n+1) - 2
def l(n):
    return 2 ** (n+2) - 3


# In[109]:


def func(i, x):
    if x == 0:
        return 0
    elif x <= l(i-1) + 1:
        return func(i-1, x-1)
    elif x == l(i-1) + 2:
        return p(i-1) + 1
    elif x <= 2 * l(i-1) + 2:
        return p(i-1) + 1 + func(i-1, x - l(i-1) - 2)
    else:
        return 2 * p(i-1) + 1


# In[110]:


print(func(n,x))

