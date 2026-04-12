h, w = map(int, input().split())
a=[list(input()) for i in range(h)]
def vert(a):
    res=[]
    for i in range(len(a)):
        if all(x=="." for x in a[i]):
            res.append(i)
    return res
def hori(a):
    res=[]
    for i in range(len(a[0])):
        if all(a[j][i]=='.' for j in range(len(a))):
            res.append(i)
    return res

while True:
    v_res=vert(a)
    if not(len(v_res)==0):
        a= [a[i] for i in range(len(a)) if not i in v_res]
            
    h_res=hori(a)
    if not(len(h_res)==0):
        a=[[a[j][i] for i in range(len(a[0])) if not i in h_res] for j in range(len(a))]
    if len(h_res+v_res)==0:
        break
for ai in a:
    print(''.join(ai))
    
    