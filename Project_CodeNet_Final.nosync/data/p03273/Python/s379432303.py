h,w=map(int,input().split())
a=[]
for i in range(h):
    a1=list(input())
    if a1!=['.']*w:
        a.append(a1)
    else:
        h-=1
i=0
while i < w:
    if [a[j][i]=='.' for j in range(h)]==[True]*h:
        w-=1
        a=[a[j][:i]+a[j][i+1:] for j in range(h)]
        #print(a)
    else:
        i+=1
for i in range(h):
    print(''.join(a[i]))