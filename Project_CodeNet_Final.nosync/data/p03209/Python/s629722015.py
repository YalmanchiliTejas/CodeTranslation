n,x = map(int,input().split())
cnt = [0]*(n+1)
pcnt = [0]*(n+1)
cnt[0] = pcnt[0] = 1
for i in range(n):
    cnt[i+1] = cnt[i]*2+3
    pcnt[i+1] = pcnt[i]*2+1

def f(lv,x):
    if lv == 0: return 1
    elif x <= 1: return 0
    elif x <= cnt[lv-1] + 1: return f(lv-1,x-1)
    elif x == cnt[lv-1] + 2: return pcnt[lv-1]+1
    elif x <= 2*cnt[lv-1] + 2: return pcnt[lv-1]+1+f(lv-1,x-cnt[lv-1]-2)
    else: return pcnt[lv]

print(f(n,x))