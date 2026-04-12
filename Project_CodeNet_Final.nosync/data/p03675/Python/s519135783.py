def ri(): return int(input())
def rli(): return list(map(int, input().split()))
def rls(): return list(input())
def pli(a): return "".join(list(map(str, a)))

n = ri()
a = rli()
b = []

if(n%2 == 1):
    for i in range(0,n,2)[::-1]:
        b.append(a[i])
    for i in range(1,n,2):
        b.append(a[i])
else:
    for i in range(1,n+1,2)[::-1]:
        b.append(a[i])
    for i in range(0,n,2):
        b.append(a[i])
print(" ".join(list(map(str, b))))
