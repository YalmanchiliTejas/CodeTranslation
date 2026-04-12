#ABC095C
def main():
    import sys
    A,B,C,X,Y = map(int, sys.stdin.readline().split())
    # cをi枚とする
    ans = -1
    for i in range(0, 2*10**5+1, 2):
        tmp = max((X-i//2)*A, 0) + i*C + max((Y-i//2)*B, 0)
        if ans ==-1 or ans > tmp:
            ans = tmp
    print(ans)
    
   
    
if __name__=='__main__':
    main()
