#ABC054C
import itertools
N, M=map(int,input().split())
a=[0]*0
b=[0]*0
order=list(itertools.permutations(range(N-1) ) )#0～N-2のN-1個の順列ができる。2を足すと、2～Nの配列。
c_patern=0
for i in range(M):
    a_tmp, b_tmp=map(int,input().split())
    a.append(a_tmp)
    b.append(b_tmp)
for i in range(len(order)):
    for j in range(N-1):
        flg = False
        if j==0:
            for k in range(M):
                if (a[k]==1 and b[k]==order[i][0]+2):
                    flg=True
                    break
        else:
            for k in range(M):
                if (a[k]==order[i][j-1]+2 and b[k]==order[i][j]+2) or (a[k]==order[i][j]+2 and b[k]==order[i][j-1]+2):
                    flg=True
                    break
        if flg==False:
            break
    if flg==True:
        c_patern+=1
print(c_patern)