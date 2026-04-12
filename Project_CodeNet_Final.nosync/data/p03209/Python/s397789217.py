N,X=map(int,input().split())
bg=[1]
l=[1]
for _ in range(N):
    bg.append(bg[-1]*2+1)
    l.append(l[-1]*2+3)

def eat(n,x):#レベル,食べる層の数
    if x<=1: return 0
    if x==l[n-1]+1: return bg[n-1]
    if x==l[n] or x==l[n]-1: return bg[n]
    if x<=l[n-1]: return eat(n-1,x-1)
    return bg[n-1]+1+eat(n-1,x-l[n-1]-2)
print(eat(N,X))
    