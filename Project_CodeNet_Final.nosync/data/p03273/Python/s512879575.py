H,W=map(int,input().split())
st=set()
list=list()
for i in range(H):
    S=input()
    if S.count('.') != W:
        list.append(S)
    tmp=S
    tmp=[int(i) for i,x in enumerate(tmp) if x == '.']
    if not st:
        tmp_set = set(tmp)
        st=st.union(tmp_set)
    else:
        tmp_set = set(tmp)
        st &=tmp_set
for x in list:
    str=''
    if not st:
        for i in range(W):
            str+=x[i]
    else:
        for i in range(W):
            if i not in st:
                str+=x[i]
    print(str)
    str=''
