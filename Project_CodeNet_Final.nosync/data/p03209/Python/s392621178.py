import sys
input = sys.stdin.buffer.readline

def main():
    N,X = map(int,input().split())
    
    p = [1]
    al = [1]
    for i in range(N):
        p.append(p[-1]*2+1)
        al.append(al[-1]*2+3)

    def eat(N,X):
        if N == 0:
            if X <= 0:
                return 0
            else:
                return 1
        elif X <= 1+al[N-1]:
            return eat(N-1,X-1)
        else:
            return eat(N-1,X-al[N-1]-2)+1+p[N-1]
            
    print(eat(N,X))

if __name__ == "__main__":
    main()
