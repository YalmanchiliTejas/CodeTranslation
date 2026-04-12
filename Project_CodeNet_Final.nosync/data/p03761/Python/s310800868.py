n=int(input())
S=[list(input()) for i in range(n)]
s1=S.pop(0)
A=[]
#s1を一文字ずつ確かめていく
for s in s1:
    flag=0
    #残ったSを一列ずつ確かめていく
    for t in S:
        #もしtにsが含まれていなければflagをonにする(操作をしない)
        if s not in t:
            flag=1
    #tにsが含まれていれば(Sの中にsが含まれているものが一つでもあれば)
    if flag==0:
        #Aにsを格納する
        A.append(s)
        #全てのSからsを取り除く
        for i in range(len(S)):
            S[i].remove(s)

A.sort()
print("".join(A))