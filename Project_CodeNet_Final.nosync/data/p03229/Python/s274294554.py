def calc_diffsum(li):
    ans = 0
    for ind,i in enumerate(li[:-1]):
        ans += abs(i-li[ind+1])
    return ans
#%%
N = int(input())
A = [int(input())for _ in range(N)]
#%%
A.sort()
li = []
li2 = []
for ind,i in enumerate(A):
    if(ind%2==1):
        li.append(A[-ind//2])
        li2.append(A[ind//2])
    else:
        li.append(A[ind//2])
        li2.append(A[-ind//2-1])

if(abs(li[-1]-li[0])>abs(li[-1]-li[-2])):
    li.insert(0,li[-1])
    del li[-1]
if(abs(li2[-1]-li2[0])>abs(li2[-1]-li2[-2])):
    li2.insert(0,li2[-1])
    del li2[-1]
print(max(calc_diffsum(li),calc_diffsum(li2)))
