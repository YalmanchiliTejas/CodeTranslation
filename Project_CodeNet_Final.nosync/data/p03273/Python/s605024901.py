h,w=map(int,input().split())
l=[input() for i in range(h)]

ans=[]

for i in range(h):
    if "#" in l[i]:
        ans.append(l[i])
        
for i in range(w):
    if all([ans[j][i]=="." for j in range(len(ans))]):
        for k in range(len(ans)):
            ans[k]=list(ans[k])
            ans[k][i]=""

for i in range(len(ans)):
    print("".join(ans[i]))