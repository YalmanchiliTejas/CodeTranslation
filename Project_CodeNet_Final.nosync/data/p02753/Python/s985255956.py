# To add a new cell, type '# %%'
# To add a new markdown cell, type '# %% [markdown]'

# %%
lst = input().split()

# %%
one = lst[0][0]
two = lst[0][1]
three = lst[0][2]


# %%
one_two = one != two
two_three = two != three
three_one = three != one


# %%
any([one_two, two_three, three_one])


# %%
if any([one_two, two_three, three_one]):
    print('Yes')
else:
    print('No')


# %%


