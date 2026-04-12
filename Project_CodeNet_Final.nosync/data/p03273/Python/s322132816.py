H,W=map(int,input().split(' '))
a = [list(input()) for i in range(H)]
tmp = []
ans = []
for i in a:
    if i != ['.']*W:
        tmp.append(i)
for i in range(W):
    l = [tmp[j][i] for j in range(len(tmp))]
    if l != ['.']*len(tmp):
        ans.append(l)
for i in range(len(ans[0])):
    print(''.join([ans[j][i] for j in range(len(ans))]))