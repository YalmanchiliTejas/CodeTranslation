n = int(input())
alist = []
for i in range(n):
    alist.append(int(input()))
alist.sort()
lar = alist[n//2:]
sma = alist[:n//2]
if n%2 == 0:
    ans = lar[0]-sma[-1]
    ans += 2*(sum(lar[1:])-sum(sma[:-1]))
    print(ans)
else:
    ans1 = lar[0]+lar[1]
    ans1 += 2*(sum(lar[2:])-sum(sma))
    ans2 = -sma[-1]-lar[0]
    ans2 += 2*(sum(lar[1:])-sum(sma[:-1]))
    print(max(ans1,ans2))