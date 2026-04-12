def tenchi(gr):
    gr_t=[[0]*len(gr) for i in range(len(gr[0]))]
    for i in range(len(gr)):
        for j in range(len(gr[i])):
            gr_t[j][i] = gr[i][j]
    return gr_t

H, W = map(int,input().split())
a=[list(input()) for i in range(H)]
#yoko
while a.count(["."]*len(a[0]))>0:
    a.remove(["."]*len(a[0]))

a_t = tenchi(a)
while a_t.count(["."]*len(a_t[0]))>0:
    a_t.remove(["."]*len(a_t[0]))
ans = tenchi(a_t)
for i in range(len(ans)):
    ansa = "".join(ans[i])
    print(ansa)