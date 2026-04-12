def ri(): return int(input())
def rli(): return list(map(int, input().split()))
def ris(): return list(input())
def pli(a): return "".join(list(map(str, a)))

r,g,b = rli()

if((100*r+10*g+b) % 4 == 0):
    print("YES")
else:
    print("NO")