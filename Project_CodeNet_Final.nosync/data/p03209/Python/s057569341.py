import sys
input=sys.stdin.readline

N,X = map(int,input().split())

total = [1]*(N+1)
pate = [1]*(N+1)
for i in range(1, N+1):
    total[i] = total[i-1]*2 + 3
    pate[i] = pate[i-1]*2 + 1

ans = 0
def f(lv):
    global ans, X
    if X == total[lv]:
        ans += pate[lv]
    else:
        X -= 1
        if X > 0:
            if X < total[lv-1]:
                f(lv-1)
            else:
                ans += pate[lv-1]
                X -= total[lv-1]                
                if X > 0:
                    ans += 1
                    X -= 1
                if X > 0:
                    f(lv-1)
                if X > 0:
                    X -= 1 # unreachable?

def main():
    f(N)
    print(ans)

if __name__ == '__main__':
    main()
