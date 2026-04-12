
h,w=map(int,input().split())
List=[]
List_gyou=[""]*w
ans=[]
kotae=[]

for i in range(h):
    a=input()
    check=set(a)
    if (check!={"."}):
        List.append(a)
        for j in range(w):
            List_gyou[j]+=a[j]
            
for i in range(w):
    check=set(List_gyou[i])
    if (check!={"."}):
        ans.append(List_gyou[i])

        
#print(ans) 
#print(len(ans))
#print(len(ans[0]))
for i in range(len(ans[0])):
    kore=""
    for j in range(len(ans)):
        kore+=ans[j][i]
    print(kore)
        

#print(List)
#print(List_gyou)