from sys import stdin
def I():
    return stdin.readline().rstrip()
def MI():
    return map(int(),stdin.readline().rstrip().split())
def LI():
    return list(map(int,stdin.readline().rstrip().split()))
n=int(I())
a=LI()
sum=0
for i in range(len(a)):
    sum+=a[i]
norm=0
for i in range(len(a)):
    norm+=a[i]**2
print(((sum**2-norm)//2)%(10**9+7))