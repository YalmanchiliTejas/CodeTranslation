N,X,M = map(int,input().split())
t_loop = [X]
f_loop = [X]
f_memo = {X:1}
s_loop = []
while True:
    new_val = t_loop[-1]**2%M
    t_loop.append(new_val)
    if new_val not in f_memo:
        f_memo[new_val] = 1
        f_loop.append(new_val)
    else:
        f_memo[new_val] += 1
        if f_memo[new_val] == 3:
            break
        else:
            s_loop.append(new_val)

ans = 0
if N <= len(f_loop):
    ans += sum(f_loop[:N])
else:
    ans += sum(f_loop)
    shou = (N-len(f_loop))//len(s_loop)
    amari = (N-len(f_loop))%len(s_loop)
    ans += shou*sum(s_loop)
    ans += sum(s_loop[:amari])
    
print(ans)