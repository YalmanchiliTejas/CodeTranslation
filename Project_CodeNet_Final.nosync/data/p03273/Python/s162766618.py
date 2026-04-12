h,w=map(int,input().split())
L=[input() for i in range(h)]

L2=[]
for i in range(h):
      if "#" in L[i]:
            L2.append(list(L[i]))
            
flag=[]
for i in range(w):
      for j in range(len(L2)):
            if L2[j][i]=="#":
                  flag.append(i)
                  break
ans=[]
ans2=[]
for i in range(len(L2)):
      for j in flag:
            ans2.append(L2[i][j])
      ans.append(ans2)
      ans2=[]

for i in range(len(ans)):
      print("".join(ans[i]))
            