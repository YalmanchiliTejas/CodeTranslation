#ABC095C 全列挙
def main():
    import sys, math
    A,B,C,X,Y = map(int, sys.stdin.readline().split())
    ans = float('inf')
    for i in range(10**5+1):
        tmp = i*2*C + max(0, (X-i)*A) + max(0, (Y-i)*B)
        ans = min(tmp, ans)
        if i > X and i > Y:
            break
    print(ans)  

if __name__=='__main__':
    main()
