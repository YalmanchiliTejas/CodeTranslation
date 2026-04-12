#-----------にゃんにゃん準備-----------#
def nyan(f=lambda x: x):
    return map(f,input().split())
def nyannyan(f=lambda x: x,i=0):
    if i==0: return list(map(f,input().split()))
    l = []
    for j in range(i):
        l.append(f(input()))
    return l
#------------にゃんにゃん------------#
n, = nyan(int)
h = nyannyan(int)
t, j = (0, 0)
for i in range(n):
    if(h[i]>=t):
        j+=1
        t=h[i]
print(j)
#---------にゃんにゃんおしまい---------#