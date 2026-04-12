N,X = map(int,input().split())
bg_cnt = [1]
pan_cnt = [1]
for i in range(N):
    bg_cnt.append(bg_cnt[i] * 2 + 3)
    pan_cnt.append(pan_cnt[i] * 2 + 1)

def f(N,X):
    if N == 0:
        return 1
    elif X == 1:
        return 0
    elif X <= 1 + bg_cnt[N-1]:
        return f(N-1,X-1)
    elif X == 2 + bg_cnt[N-1]:
        return 1 + f(N-1,X-1)
    else:
        return pan_cnt[N-1] + 1 + f(N-1,X-2-bg_cnt[N-1])    
print(f(N,X))