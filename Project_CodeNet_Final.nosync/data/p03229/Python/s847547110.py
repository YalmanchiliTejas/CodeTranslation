import sys,bisect as bs,collections as cl,heapq as hq
sys.setrecursionlimit(100000)
mod = 10**9+7
Max = sys.maxsize
def l(): #intのlist
    return list(map(int,input().split()))
def m(): #複数文字
    return map(int,input().split())
def onem(): #Nとかの取得
    return int(input())
def s(x): #圧縮
    a = []
    aa = x[0]
    su = 1
    for i in range(len(x)-1):
        if aa != x[i+1]:
            a.append([aa,su])
            aa = x[i+1]
            su = 1
        else:
            su += 1
    a.append([aa,su])
    return a
def jo(x): #listをスペースごとに分ける
    return " ".join(map(str,x))
def max2(x): #他のときもどうように作成可能
    return max(map(max,x))
def In(x,a): #aがリスト(sorted)
    k = bs.bisect_left(a,x)
    if k != len(a) and a[k] ==  x:
        return True
    else:
        return False

n = onem()
a = []
for i in range(n):
    a.append(onem())
a.sort()
bbb = a[n//2+(n%2):]
bbb.reverse()

bbbb = a[n//2:]

if len(bbb) >= 3:
    bbbb = [bbbb[0]] + bbbb[2:] + [bbbb[1]]


aaa = a[:n//2+(n%2)]
if len(aaa) >= 3:
    aaa = [aaa[-1]] + aaa[:-2] + [aaa[-2]]

aaaa = a[:n//2]

lll = []
llll = []

for i in range(n):
    if i % 2 == 0:
        lll.append(aaa[i//2])
        llll.append(bbbb[i//2])
    else:
        lll.append(bbb[i//2])
        llll.append(aaaa[i//2])
ans = 0
an = 0
for i in range(n):
    if i == 0:
        st = lll[0]
        stt = llll[0]
    else:
        ans += abs(lll[i] - st)
        st = lll[i]
        an += abs(llll[i] - stt)
        stt = llll[i]
print(max(ans,an))





