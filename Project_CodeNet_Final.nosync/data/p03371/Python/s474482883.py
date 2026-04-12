#ABC095C
def main():
    import sys, math
    A,B,C,X,Y = map(int, sys.stdin.readline().split())
    L =[]
    #全部C
    L.append(max(X, Y)*2*C)
    
    #できるだけC 不足分A,B
    if X <= Y:
        L +=[X*2*C + (Y-X)*B]
    else:
        L +=[Y*2*C + (X-Y)*A]
    
    #全部A,B
    L.append(A*X+B*Y)
    print(min(L))


if __name__=='__main__':
    main()
