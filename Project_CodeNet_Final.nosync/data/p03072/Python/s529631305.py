import sys
sys.setrecursionlimit(10**9)

def mi(): return map(int,input().split())
def ii(): return int(input())
def isp(): return input().split()
def deb(text): print("-------\n{}\n-------".format(text))

def main():
    N=ii()
    H=list(mi())

    ans = 0
    for i in range(N):
        h = H[i]
        for j in range(i):
            if H[j] > h:
                break
        else:
            ans += 1
            continue
            
        
       
    print(ans)


                





if __name__ == "__main__":
    main()