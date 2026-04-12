#import sys
#input = sys.stdin.

def main():
    N = int(input())
    num = 97
    T = [[0 for _ in range(N)] for _ in range(26)]
    for i in range(N):
        S = list(map(str,input()))
        for moji in S:
            T[ord(moji)-num][i] += 1
            
    ans = ""
    for i in range(26):
        use = min(T[i])
        ans += chr(num+i)*use
    
    print(ans)

if __name__ == "__main__":
    main()