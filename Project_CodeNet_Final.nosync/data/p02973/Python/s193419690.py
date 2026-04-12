from bisect import bisect_right
N = int(input())
Alist = [int(input()) for i in range(N)]

num_col = 1
L = [-1*Alist[0]] 
for ai in Alist[1:]:
    #print(L)
    ai =-1*ai
    if ai >= L[-1]:
        L.append(ai)
        num_col += 1
    else:
        L[bisect_right(L, ai)] = ai
print(num_col)