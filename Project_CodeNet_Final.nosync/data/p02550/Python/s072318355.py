n,x,m = map(int,input().split())

ans = []
chk = [0]*(m+1)

tmp = x
tmp %= m
idx = 0

for i in range(n):
    ans.append(tmp)
    if tmp == 0:
        print(sum(ans))
        exit()
    if chk[tmp] == 1:
        idx = i
        break
    chk[tmp] = 1
    tmp *= tmp
    tmp %= m

if idx == 0:
    print(sum(ans))
    exit()

li = [0]*(m+1)

l_num = ans[-1]

for i in range(len(ans)):
    if l_num == ans[i]:
        f_idx = i
        break

li[0] = l_num

shuki = len(ans)-f_idx-1

for i in range(1,shuki):
    li[i] = li[i-1] + ans[f_idx+i]

t_ans = 0
t_ans += (n-idx-1) // shuki * li[shuki-1]
t_ans += li[(n-idx-1) % shuki]

print(sum(ans)-ans[-1]+t_ans)
#print(t_ans,n,sum(ans),li[shuki])