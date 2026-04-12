h,w=map(int,input().split())
a=[]
for i in range(h):
    tmp=str(input())
    if '#' in tmp:
        a.append(tmp)
delete=[-1]
for i in range(w):
    for j in range(len(a)):
        if a[j][i]=='#':
            break
        else:
            if j==len(a)-1:
                delete.append(i)
if delete==[]:
    delete.append(w)
for i in range(len(a)):
    for j in range(1,len(delete)):
        print(a[i][delete[j-1]+1:delete[j]],end="")
    if delete[-1]<w-1:
        print(a[i][(delete[-1]+1):],end="")
    print("")