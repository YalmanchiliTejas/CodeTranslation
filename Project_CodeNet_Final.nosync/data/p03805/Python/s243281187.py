from itertools import permutations
 
N,M = map(int,input().split())
ans=0
s = []
 
for i in range(M):
    a,b = map(int,input().split())
    s.append([a,b])

#print(s) #[[1, 2], [1, 3], [2, 3]]

t=list(permutations(list(range(1,N+1))))

##print(t) [(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)]

for i in range(len(t)):
    flag=True
    if t[i][0]!=1: continue #1スタートのみ。continue文はfor文やwhile文などループ内の処理をスキップ
    for j in range(N-1):
        a=sorted([t[i][j],t[i][j+1]]) #(1,2,3)なら[(1,2)]や[(2,3)]
        #print(i)# 0 0 1 1
        #print(j)# 0 1 0 1
        #print(a)# [1, 2] [2, 3] [1,3] [2,3]
        if a not in s: flag=False
    if flag == True:
        ans = ans + 1

print(ans)