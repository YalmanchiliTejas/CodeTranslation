import collections
n=int(input())
S=[list(input()) for _ in range(n)]
tables=[]
tables2=[]
l=[]
l2=[]
l3=[]
for i in range(n):
    c = collections.Counter(S[i])
    tables2.append(c)
    values = list(c.values())  # aのCollectionのvalue値のリスト(n_1こ、n_2こ…)
    key = list(c.keys())  # 先のvalue値に相当する要素のリスト(要素1,要素2,…)
    for j in range(len(key)):
        l.append([key[j], values[j]])  # lは[要素i,n_i]の情報を詰めたmatrix
    tables.append(l)
    l=[]
l=[]
#print(tables)
for i in range(97,123):
    #print(chr(i))
    for j in range(len(tables2)):
        #print(tables2[j][chr(i)])
        l.append(tables2[j][chr(i)])
    if min(l)>0:
        l2.append([chr(i),min(l)])
    l=[]
l2.sort(key=lambda x:x[0])
for i in range(len(l2)):
    l3.extend([l2[i][0]]*l2[i][1])
print(*l3,sep="")