n=int(input())
s=input()

l = [0] * n
l2 = [0 if s[i]=='o' else 1 for i in range(n)]
def f(x,y):
    l[0]=x
    l[1]=y
    for i in range(2,n):
        l[i]=l[i-2]^l[i-1]^l2[i-1]
    if l[0] == l[n-2]^l[n-1]^l2[n-1] and l[1]==l[n-1]^l[0]^l2[0]:
        return True
    else: return False

if f(0,0):
    print(''.join(['S' if not l[i] else 'W' for i in range(n)]))
elif f(0,1):
    print(''.join(['S' if not l[i] else 'W' for i in range(n)]))
elif f(1,0):
    print(''.join(['S' if not l[i] else 'W' for i in range(n)]))
elif f(1,1):
    print(''.join(['S' if not l[i] else 'W' for i in range(n)]))
else:print(-1)