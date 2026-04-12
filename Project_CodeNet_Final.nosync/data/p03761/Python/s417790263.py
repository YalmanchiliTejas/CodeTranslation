import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N = int(input())
lis = list(input())
lis.sort()
for i in range(N-1):
    string = list(input())
    nx = []
    for l in lis:
        if l in string:
            nx.append(l)
            string.remove(l)
    lis = nx
lis.sort()
print(''.join(lis))