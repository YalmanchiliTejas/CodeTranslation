n, x, m = map(int, input().split())
di = {}
for i in range(m+1):
    di[i] = -1
li = []
for i in range(m+1):
    li.append(x)
    di[x] = i
    x = pow(x, 2, m)
    if di[x]  >= 0:
        break
#print(li)
#print(x)
ans = 0
#print(di[x])
for j in range(di[x]):
    ans += li[j]
loop_sum = 0
for j in range(di[x], i+1):
    loop_sum += li[j]
#print(loop_sum)
loop = i+1-di[x] #1ループ何個か
#print(loop)
n -= di[x]
k = n//loop # 何回ループするか
ans += loop_sum * k
#print(ans)
kk = n-k*loop #残り
#print(kk)
ans += sum(li[di[x]:di[x]+kk])
print(ans)