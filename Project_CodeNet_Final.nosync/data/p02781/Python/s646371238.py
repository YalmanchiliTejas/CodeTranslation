import sys
#input = sys.stdin.buffer.readline

def main():
    N = str(input())
    K = int(input())
    
    l = len(N)
    dpa = [[0 for _ in range(K+1)] for _ in range(l)]
    dpb = [[0 for _ in range(K+1)] for _ in range(l)]
    
    dpa[0][0],dpa[0][1],dpb[0][1] = 1,int(N[0])-1,1
    for i in range(1,l):
        dpa[i][0] = 1
        num = int(N[i])
        if num == 0:
            for j in range(K):
                j += 1
                dpa[i][j] = dpa[i-1][j-1]*9 + dpa[i-1][j]
                dpb[i][j] = dpb[i-1][j]
        else:
            for j in range(K):
                j += 1
                dpa[i][j] = dpa[i-1][j-1]*9 + dpa[i-1][j] + dpb[i-1][j-1]*(num-1) + dpb[i-1][j]
                dpb[i][j] = dpb[i-1][j-1]

    print(dpa[l-1][K]+dpb[l-1][K])

if __name__ == "__main__":
    main()
