h,w=map(int,input().split())
a=[input() for i in range(h)]
hi=[]
we=[]
def str_del(str,index):
    str = str[:index]+str[index+1:]
    return str

for i in range(h):

    if a[i] =='.'*w:
        we+=[i]

for i in range(w):
    memo=[]
    for j in range(h):
        memo+=a[j][i]
    if ''.join(memo) =='.'*h:
        hi+=[i]

for i in we[::-1]:
    a.pop(i)
for z in range(len(a)):
    for x in hi[::-1]:
        a[z]=str_del(a[z], x)

for i in a:
    print(i)