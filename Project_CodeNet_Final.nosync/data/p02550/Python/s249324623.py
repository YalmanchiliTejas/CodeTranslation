N,X,M = map(int,input().split())
A = set()
ans = []
a = X
flg = 0
while True:
    k = len(A)
    A.add(a)
    if len(A) == k:
        break
    if a == 0:
        flg =1
        ans.append(a)
        break
    ans.append(a)
    a = a**2%M

g = ans.index(a)
ans_first = ans[:g]
ans = ans[g:]
ans_cum = [ans[0]]
for i in range(len(ans)-1):
    ans_cum.append(ans_cum[i]+ans[i+1])
check = len(ans_cum)
N -= len(ans_first)
if N < 0:
    final = ans_first[:N]
    print(sum(final))
    exit()
loop = N//check
spare = N%check
res = 0
if flg == 0:
    if spare > 0:
        res=loop*ans_cum[-1]+ ans_cum[spare-1]+sum(ans_first)
    else:
        res=loop*ans_cum[-1]+sum(ans_first)
    print(res)
else:
    print(sum(ans_first))