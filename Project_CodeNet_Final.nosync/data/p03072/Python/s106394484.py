import sys
input = sys.stdin.readline
def main():
    N = int(input())
    H = list(map(int, input().split()))
    if N == 1:
        return print(1)
    CNT = 1
    High = H[0]
    for i in range(1,N):
        if H[i] >= High:
            CNT += 1
            High = H[i]
        
    return print(CNT)

if __name__ == '__main__':
    main()