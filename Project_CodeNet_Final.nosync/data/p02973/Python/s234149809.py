#%%
import bisect

n = int(input())
a = [0] * n
for i in range(n):
    a[i] = int(input())

ans_list = [-1] * n
for i in range(n):
    tmp = bisect.bisect_left(ans_list, a[i])
    #print(tmp)
    if tmp == 0:
        ans_list.insert(0, a[i])
    else:
        ans_list[tmp-1] = a[i]
    #print(ans_list)

ans = 0
for i in range(n):
    if ans_list[i] != -1:
        ans += 1
print(ans)

    
