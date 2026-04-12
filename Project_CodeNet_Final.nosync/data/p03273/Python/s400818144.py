#インポート
import sys

#入力用
def ILI(): return list(map(int, sys.stdin.readline().rstrip().split()))
def ISI(): return map(int, sys.stdin.readline().rstrip().split())
def II(): return int(sys.stdin.readline().rstrip())
def ISS(): return sys.stdin.readline().rstrip().split()
def IS(): return sys.stdin.readline().rstrip()

H, W = ISI()
a = [[j for j in IS()] for i in range(H)]
b = []
for x in a:
    if "#" in x:
        b.append(x)
c = []
for y in zip(*b):
    if "#" in y:
        c.append(y)
for a in zip(*c):
    print("".join(a))