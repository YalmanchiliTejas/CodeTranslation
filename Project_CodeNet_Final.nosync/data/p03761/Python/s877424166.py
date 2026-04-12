n= int(input())
S=[]
for _ in range(n):
    S.append(input())
alpha=[[0]*26 for _ in range(n)]
#print(alpha)
for i in range(n):
    for c in S[i]:
        alpha[i][ord(c)-97]+=1
#print(alpha)
answer=''
for j in range(26):
    m=min([el[j] for el in alpha])
    answer+=chr(j+97)*m
print(answer)