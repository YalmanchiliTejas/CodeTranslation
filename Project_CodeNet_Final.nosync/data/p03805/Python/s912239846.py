n,m=(int(i) for i in input().split())
mtrx=[[int(i) for i in input().split()] for j in range(m)]
#print(mtrx)
mtrx+=[[mtrx[i][1],mtrx[i][0]] for i in range(m)]
#print(mtrx)
mylist=[10*mtrx[i][0]+mtrx[i][1] for i in range(len(mtrx))]
#print(mylist)
# 順列を格納するリスト
perm = []
cnt=[]
# 順列の生成
def make_perm(n, m = 0):
    if n == m and perm[0]==1:
        flag=1
        for i in range(len(perm)-1):
            myval=10*perm[i]+perm[i+1]
            myval1=mylist.count(myval)
            flag=flag*myval1
        cnt.append(flag)
        
    else:
        for x in range(1, n + 1):
            if x in perm: continue
            perm.append(x)
            make_perm(n, m + 1)
            perm.pop()
            
make_perm(n)
print(sum(cnt))
