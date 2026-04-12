N = int(input())
src = [input() for i in range(N)]
def ctoi(c):
    return ord(c) - ord('a')
def itoc(i):
    return chr(ord('a') + i)

ans = [999] * 26
for s in src:
    tmp = [0] * 26
    for c in s:
        tmp[ctoi(c)] += 1
    for i,(a,b) in enumerate(zip(ans,tmp)):
        ans[i] = min(a,b)

t = ''
for i,a in enumerate(ans):
    t += itoc(i) * a
print(t)
