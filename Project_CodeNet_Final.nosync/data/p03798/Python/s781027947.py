#import sys
#input = sys.stdin.buffer.readline

def main():
    N = int(input())
    S = str(input())
    
    def animal(x,s):
        if x[-1] == 1:
            if s == "o":
                return x[-2]
            else:
                return -1*x[-2]
        else:
            if s == "o":
                return -1*x[-2]
            else:
                return x[-2]
                
    poss = [[1,1],[1,-1],[-1,1],[-1,-1]]
    for i in range(4):
        col = poss[i]
        for j in range(N-1):
            put = animal(col,S[j+1])
            col.append(put)
        put = animal(col,S[0])
        col.append(put)
        if (col[0] == col[-2] and col[1] == col[-1]):
            l = len(col)-2
            ans = []
            for k in range(l):
                if col[k] == 1:
                    ans.append("S")
                else:
                    ans.append("W")
            print("".join(ans))
            exit()
            
    print(-1)
    
if __name__ == "__main__":
    main()