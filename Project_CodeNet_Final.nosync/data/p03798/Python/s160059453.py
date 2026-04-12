import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

def main():
    n=II()
    s=SI()
    ans=[-1]*n
    for f in range(2):
        for e in range(2):
            ans[0]=f
            ans[-1]=e
            for i,c in enumerate(s):
                if c=="o":
                    if ans[i]:ans[(i+1)%n]=ans[i-1]
                    else:ans[(i+1)%n]=1-ans[i-1]
                else:
                    if ans[i]:ans[(i+1)%n]=1-ans[i-1]
                    else:ans[(i+1)%n]=ans[i-1]
            if ans[0]==f and ans[-1]==e:
                print("".join("S" if a else "W" for a in ans))
                exit()
    print(-1)

main()