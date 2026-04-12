# ABC 152 A
si = lambda: input()
ni = lambda: int(input())
nm = lambda: map(int, input().split())
snm = lambda: map(str, input().split())
nl = lambda: list(map(int, input().split()))
n,m=nm()
if m/n==1.0:
    print('Yes')
else:
    print('No')