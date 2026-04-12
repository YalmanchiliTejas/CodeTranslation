def main():
    N = int(input())
    s = list(input())
    K = int(input())
    
    base = s[K-1]
    for i in range(N):
        if s[i] != base:
            s[i] = "*"
            
    print(*s,sep="")
    
if __name__ == "__main__":
    main()
