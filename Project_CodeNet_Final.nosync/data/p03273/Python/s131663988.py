H,W = list(map(int,input().split()))
b = []
if H == 1:
    print(input())
else:
    for _ in range(H):
        a = input()
        if a.count('.') == W:
            pass
        else:
            b.append(a)
    st = set()
    #print(b)
    for i,c in enumerate(b[0]):
        if c == '.':
            st.add(i)
    for a in b[1:]:
        s_st = set()
        for k in st:
            if a[k] == '#':
                s_st.add(k)
        st -= s_st
    #print(st)
    for c in b:
        for i,d in enumerate(c):
            if not i in st:print(d,end='')
        else:print('')