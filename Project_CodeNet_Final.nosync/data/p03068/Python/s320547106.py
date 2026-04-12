N=int(input());S=input();K=int(input())
list_=[]
moj = ""
for i in range(N):
 if S[i]!=S[K-1]:
  moj += "*"
 else:
  moj += S[i]
print(moj)
