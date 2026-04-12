n = int(input())
s = input()
k = int(input())

#%%
#n, s, k = 5, "error", 2

#%%
mask = s[k-1]

#%%
ans = []
for i in range(n):
    if s[i] != mask:
        ans.append("*")
    else:
        ans.append(mask)
#%%
print("".join(ans))

#%%
