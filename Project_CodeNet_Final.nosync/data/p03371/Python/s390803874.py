import sys
sys.setrecursionlimit(10**9)

def mi(): return map(int,input().split())
def ii(): return int(input())
def isp(): return input().split()
def deb(text): print("-------\n{}\n-------".format(text))

INF=10**20
def main():
    A,B,C,X,Y = mi()

    ans = INF
    for z in range(10**6):
        x = max(0,X-z//2)
        y = max(0,Y-z//2)

        ans = min(A*x+B*y+C*z,ans)
    
    print(ans)




if __name__ == "__main__":
    main()