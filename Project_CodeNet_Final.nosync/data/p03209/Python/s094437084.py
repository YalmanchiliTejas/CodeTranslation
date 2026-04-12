import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N, X = mapint()
burger = [1]*50
pa = [1]*50
for i in range(1, 50):
    burger[i] = burger[i-1]*2+3
    pa[i] = pa[i-1]*2+1

to_eat = X
layer = N
ans = 0
while 1:
    if layer==0:
        ans += to_eat
        break
    if to_eat<=1:
        break
    elif to_eat==burger[layer-1]+2:
        ans += pa[layer-1]+1
        break
    elif to_eat==burger[layer-1]+1:
        ans += pa[layer-1]
        break
    elif to_eat==burger[layer-1]*2+3:
        ans += pa[layer-1]*2+1
        break
    elif to_eat<=burger[layer-1]:
        layer -= 1
        to_eat -= 1
        continue
    else:
        ans += pa[layer-1]+1
        to_eat -= burger[layer-1]+2
        layer -= 1

print(ans)